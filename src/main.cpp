/**
 * @file main.cpp
 * @author 恒星不见
 * @brief
 * @version 0.1
 * @date 2024-02-17
 *
 * @copyright Copyright (c) 2024
 *
 */
/**************************************************************/
#include <Arduino.h>
#include "demos/lv_demos.h"
#include "display.h"
#include "function.h"
#include "extra/widgets/lv_widgets.h"

/******************guider头文件与界面声明**********************/
#include <gui_guider.h>
#include <custom.h>
#include <events_init.h>
/*************************************************************/
#include <lv_examples.h>
/************************Define*******************************/

/*************************************************************/
Display screen;
lv_ui guider_ui;
hw_timer_t *timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;
uint8_t display_id = 0;
int chart_up = 90;
int chart_down = 20;
float pid_p = 3.0;
float pid_i = 5.0;
float pid_d = 1.0;
float PidE1 = 0.0f;
float R_pid_p = 15;
float R_pid_d = 5;
float R_pid_min_p = 35;
bool over = false;
int rate = 25;
float target_temperature = 75.0;
float voltage = 5.0;
float electric_current = 1.0;
float power = 5.0;
float current_temperature = 25.0;
float cur_1 = 0.0f;
float real_rate = 0.0f;
volatile int interruptCounter;
unsigned long start_time;
unsigned long current_time;
void IRAM_ATTR onTimer()
{
  portENTER_CRITICAL_ISR(&timerMux);
  interruptCounter++;
  portEXIT_CRITICAL_ISR(&timerMux);
}

void setup()
{
  /* Init Serial */
  Serial.begin(9600);
  /* Init lvgl display port */
  screen.init();
  screen.setBackLight(0.2);
  /*********Timer************/
  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 10000, true); // 10ms
  // timerAlarmEnable(timer);
  /********************Init****************************/
  all_init();
  /*********************demo and example****************/
  // lv_demo_widgets();
  // lv_demo_benchmark();
  // lv_demo_music();
  // lv_example_chart_1();
  /*****************GUI_guider**************************/
  srand((time(NULL)));
  setup_ui(&guider_ui);
  events_init(&guider_ui);
  /* Inflate GUI objects */
  start_time = millis();
}

void loop()
{
  // run this as often as possible
  screen.routine();
  if (display_id == 1)
  {
    timerAlarmEnable(timer);
    if (interruptCounter > 0)
    {
      portENTER_CRITICAL(&timerMux);
      interruptCounter--;
      // if(interruptCounter_100>100)
      // {
      //   interruptCounter_100 = 0;
      // }
      portEXIT_CRITICAL(&timerMux);
      /****************/
      chart_update(&guider_ui, current_temperature, target_temperature);
      chart_range(&guider_ui, chart_down, chart_up); 
      /****************/
    }
    current_time = millis();
    if(current_time - start_time > 500)
    {
      real_rate = (current_temperature - cur_1) * 120;
      start_time = current_time;
      Serial.printf("real_rate:%.2f\n",real_rate);
      cur_1 = current_temperature;
    }
    //Serial.printf("%ld,%ld\n",current_time,start_time);
    int pot_val = pot_read();
 
    if (pot_val > 4000)
    {
      heat_pwm_write(0);
      fan_pwm_write(0);
    }
    else if (pot_val > 2000)
    {
      fan_pwm_write(0);
      float pwm = pid(target_temperature, current_temperature);
      heat_pwm_write(pwm);
    }
    else if (pot_val > 1200)
    {
      float pwm = pid(target_temperature, current_temperature);
      heat_pwm_write(pwm);
      fan_ctl(target_temperature, current_temperature);
    }
    else if (pot_val > 100)
    {
      heat_pwm_write(0);
      fan_ctl(target_temperature, current_temperature);
    }
    else
    {
      heat_pwm_write(0);
      fan_pwm_write(2500);
    }
    voltage = voltage_read() * 2.98;
    electric_current = voltage / CEMENT_RES;
    current_temperature = gy906_read_target();
    temp_update(&guider_ui, current_temperature);
    power_update(&guider_ui, voltage, electric_current);
  }
  else
  {

    timerAlarmDisable(timer);
    heat_pwm_write(0);
    fan_pwm_write(0);
  }

  /* Serial test */
  // Serial.println("hello");
}
