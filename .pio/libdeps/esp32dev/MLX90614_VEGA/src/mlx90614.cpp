/***************************************************************************
* Module name                           :  mlx90614.c
* Name of Author                        :  Siva Prasad S, C-DAC
* Email ID  (Report any bugs)           :  sivaprasad@cdac.in
* Module Description                    :  Library for mlx90614 Temperature sensor.

  Copyright (C) 2021  CDAC(T). All rights reserved.

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.

***************************************************************************/


#include "mlx90614.h"
#include<Arduino.h>


#define sclPin 22
#define sdaPin 21



void mlx90614Start()
{
  pinMode(sclPin,OUTPUT);
  pinMode(sdaPin,OUTPUT);
  

  digitalWrite(sdaPin, HIGH);
  digitalWrite(sclPin, HIGH);
  delayMicroseconds(250);
  digitalWrite(sdaPin, LOW);
  delayMicroseconds(5);
  digitalWrite(sclPin, LOW);
}

void mlx90614Stop()
{
  pinMode(sclPin,OUTPUT);
  pinMode(sdaPin,OUTPUT);

  digitalWrite(sdaPin, LOW);
  digitalWrite(sclPin, HIGH);
  delayMicroseconds(10);
  delayMicroseconds(10);
  digitalWrite(sdaPin, HIGH);
  delayMicroseconds(10);
}

void mlx90614Restart()
{
  pinMode(sclPin,OUTPUT);
  pinMode(sdaPin,OUTPUT);

  digitalWrite(sdaPin, LOW);
  digitalWrite(sclPin, LOW);
  delayMicroseconds(5);
  digitalWrite(sdaPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(sclPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(sdaPin, LOW);
  delayMicroseconds(5);
  digitalWrite(sclPin, LOW);
}

void writebyte( unsigned char data)
{
  pinMode(sclPin,OUTPUT);
  pinMode(sdaPin,OUTPUT);

  digitalWrite(sdaPin, LOW);
  digitalWrite(sclPin, LOW);

  for (int i = 0; i < 8; i++)
  {
    //delayMicroseconds(5);
    if (data & 0x80)
    {
      digitalWrite(sdaPin, HIGH);
    }
    else
    {
      digitalWrite(sdaPin, LOW);
    }
    data = data << 1;
    delayMicroseconds(5);
    digitalWrite(sclPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(sclPin, LOW);
  }
  //ACK = GPIO_read_pin(SDA);
  pinMode(sdaPin,INPUT);
  delayMicroseconds(5);
  digitalWrite(sclPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(sclPin, LOW);
}
unsigned char readbyte()
{
  unsigned char data = 0, bits;
  pinMode(sclPin,OUTPUT);
  pinMode(sdaPin,INPUT);


 // digitalWrite(sdaPin, HIGH);
  digitalWrite(sclPin, LOW);
  delayMicroseconds(5);

  for (int i = 0; i < 8; i++)
  {
    delayMicroseconds(5);
    digitalWrite(sclPin, HIGH);
    delayMicroseconds(5);
    bits = digitalRead(sdaPin);
    digitalWrite(sclPin, LOW);
    data = data | (bits << (7 - i));
  }
  //ack
  pinMode(sdaPin,OUTPUT);
  digitalWrite(sdaPin, LOW);
  delayMicroseconds(5);
  digitalWrite(sclPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(sclPin, LOW);
  return data;
}
double mlx90614ReadTempC(unsigned char reg)
{
  double tempC;
  unsigned int tempData = 0;
  mlx90614Start();
  writebyte(MLX90614_WRITE_ADDR);
  writebyte(reg);
  mlx90614Restart();
  writebyte(MLX90614_READ_ADDR);
  tempData = readbyte();
  tempData |= readbyte() << 8;
  mlx90614Stop();
  tempC = tempData * 0.02;
  tempC -= 273.15;
  return tempC;
}

double mlx90614ReadAmbientTempC()
{
  return mlx90614ReadTempC(MLX90614_AMBIENT_TEMP);
}

double mlx90614ReadTargetTempC()
{
  return mlx90614ReadTempC( MLX90614_TARGET_TEMP);
}
