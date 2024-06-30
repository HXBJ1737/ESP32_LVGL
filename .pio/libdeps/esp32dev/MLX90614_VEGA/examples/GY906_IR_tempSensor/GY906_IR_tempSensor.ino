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

//#define sclPin 6
//#define sdaPin 5


 double temperature;
 


void setup()
{
  delay(2000);
  Serial.begin(115200);
  Serial.println("+-----[ mlx90614 dci Temperature Sensor Demo ]-----+");
  Serial.println("|                                                  |");
  Serial.println("|                 SCL ---> GPIO6                   |");
  Serial.println("|                 SDA ---> GPIO5                   |");
  Serial.println("|                                                  |");
  Serial.println("+--------------------------------------------------+");
//  mlx90614 myTempSensor;
  

 // myTempSensor.sclPin = 6;
 // myTempSensor.sdaPin = 5;
}

//int udelay(unsigned int count)
//{
 // for(int i=0;i<(count*35);i++); //delay millisecond calculation with board mhz
//}

 void loop ()
  {
   
    temperature = mlx90614ReadAmbientTempC();
    Serial.print("Ambient Temp : ");
    Serial.print(temperature);
    temperature = mlx90614ReadTargetTempC();
    Serial.print("   Target Temp :");
     Serial.println(temperature);
    delay(500);
  }
