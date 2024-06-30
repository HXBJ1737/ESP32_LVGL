#ifndef FUNCTION_H
#define FUNCTION_H

#include <lvgl.h>
#include <Arduino.h>
#include "lvgl.h"
#include "gui_guider.h"
#include "mlx90614.h"

#define BLINK_PIN 23
#define HEAT_PWM_PIN 16
#define HEAT_PWM_CHANNEL 2
#define FAN_PWM_PIN 0
#define FAN_PWM_CHANNEL 5
#define POT_ADC_PIN 4
#define NTC_ADC_PIN 13
// #define GY906_SDA_PIN 21
// #define GY906_SCL_PIN 22
#define INA226_SDA_PIN 27
#define INA226_SCL_PIN 14
#define VOLTAGE_ADC_PIN 12
#define CEMENT_RES 10.0
#define NTC_VD_RES 1.66
extern float pid_p;
extern float pid_i;
extern float pid_d;
extern float PidE1;
extern float R_pid_p;
extern float R_pid_d;
extern float R_pid_min_p;
extern int rate;
extern int chart_up;
extern int chart_down;
extern unsigned long per_endtime;
extern float real_rate;
extern bool over;
void chart_range(lv_ui *ui, int i, int j);
void chart_update(lv_ui *ui, float cur, float per);
void power_update(lv_ui *ui, float u, float i);
void temp_update(lv_ui *ui, float t);
void all_init();
int pot_read();
int ntc_read();
void heat_pwm_write(int pwm);
void fan_pwm_write(int pwm);
double gy906_read_ambient();
double gy906_read_target();
float voltage_read();
bool fan_ctl(float target, float current);
float pid(float target, float current);
#endif
