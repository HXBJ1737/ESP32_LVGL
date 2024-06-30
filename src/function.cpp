#include <function.h>
void chart_range(lv_ui *ui, int i, int j)
{
    lv_chart_set_range(ui->screen_1_chart_1, LV_CHART_AXIS_PRIMARY_Y, i, j);
}
void chart_update(lv_ui *ui, float cur, float per)
{
    lv_chart_set_next_value(ui->screen_1_chart_1, ui->screen_1_chart_1_0, cur);
    lv_chart_set_next_value(ui->screen_1_chart_1, ui->screen_1_chart_1_1, per);
    lv_chart_refresh(ui->screen_1_chart_1);
}
void power_update(lv_ui *ui, float u, float i)
{
    lv_label_set_text_fmt(ui->screen_1_label_6, "U:%.2fV ", u);
    lv_label_set_text_fmt(ui->screen_1_label_7, "I:%.2fA ", i);
    lv_label_set_text_fmt(ui->screen_1_label_8, "P:%.2fW ", u * i);
}
void temp_update(lv_ui *ui, float t)
{
    lv_label_set_text_fmt(ui->screen_1_label_10, "Current:%.2fC", t);
}
void all_init()
{
    pinMode(BLINK_PIN, OUTPUT);

    ledcSetup(HEAT_PWM_CHANNEL, 10000, 12);
    ledcAttachPin(HEAT_PWM_PIN, 2);
    ledcWrite(HEAT_PWM_CHANNEL, 0);

    ledcSetup(FAN_PWM_CHANNEL, 10000, 12);
    ledcAttachPin(FAN_PWM_PIN, FAN_PWM_CHANNEL);
    ledcWrite(FAN_PWM_CHANNEL, 0);
}
int pot_read()
{
    return analogRead(POT_ADC_PIN);
}
int ntc_read()
{
    return analogRead(NTC_ADC_PIN);
}
void heat_pwm_write(int pwm)
{
    ledcWrite(HEAT_PWM_CHANNEL, pwm);
}
void fan_pwm_write(int pwm)
{
    ledcWrite(FAN_PWM_CHANNEL, pwm);
}
double gy906_read_ambient()
{
    return mlx90614ReadAmbientTempC();
}
double gy906_read_target()
{
    return mlx90614ReadTargetTempC();
}
float voltage_read()
{
    float u, sum = 0.0;
    for (int i = 0; i < 255; i++)
    {
        u = (float)analogReadMilliVolts(VOLTAGE_ADC_PIN) / 1000;
        if (u < 0.28)
            u = 0;
        sum += u;
    }

    return (sum / 255);
}
bool fan_ctl(float target, float current)
{
    if (current - target > 0.5)
    {
        fan_pwm_write(2500);
        heat_pwm_write(0);
        return true;
    }
    else
    {
        fan_pwm_write(0);
        return false;
    }
}

// float temp = 0.0f; // 传感器温度,全局变量
float pid(float target, float current)
{
    float ee;
    float PidE0 = 0.0f;
    float PidOut = 0.0f;
    float PidSum = 0.0f, I_out = 0.0f;
    float r_e0 = 0.0f;
    float r_ee;
    static float r_e1 = 0.0f;
    // static float PidE1 = 0.0f;

    PidE0 = target - current; // 本次偏差
    ee = (PidE0 - PidE1);     // 计算一阶偏差

    if (ee > 2.0f)
        ee = 2.0f;
    else if (ee < -2.0f)
        ee = -2.0f;
    PidSum += PidE0; // 偏差之和

    if (PidSum > 5.0f)
        PidSum = 5.0f;
    else if (PidSum < -3.0f)
        PidSum = -3.0f;

    PidOut = pid_p * PidE0 + pid_d * ee; // 计算PID的比例和微分输出

    if (fabs(PidE0) < 1.0f) // 如果温度相差小于3度则计入PID积分输出
    {
        if (PidSum > 5.0f)
            PidSum = 5.0f;
        else if (PidSum < -2.0f)
            PidSum = -2.0f;

        I_out = pid_i * PidSum; // 积分输出

        if (fabs(PidE0) < 1.0f) // 当前温度高于设定温度0.5度时，累计积分限制
        {
            if (PidSum > 5.5f)
                PidSum = 5.5f;
            if (PidSum > 0)
                I_out -= 1; //。 当前温度高于设定温度0.5度时,消弱积分正输出
        }

        PidOut += I_out;
    }
    else
    {
        PidSum = 0.0f;
    }

    PidOut *= 500;
    if (PidE0 > 25)
        over = false;
    if (PidE0 < 1) // 超
        over = true;
    if (PidE0 < -1)
    {
        PidOut = 0;
    }
    if (PidE0 < 3 && over == false)
    {
        PidOut /= 2;
    }
    if (over == true)
    {
        PidOut = PidOut;
    }
    else
    {

        r_e0 =rate-real_rate;
        r_ee = r_e0 - r_e1;
        if (r_ee > 10.0f)
            r_ee = 10.0f;
        else if (r_ee < -10.0f)
            r_ee = -10.0f;
        r_e1 = r_e0;
        PidOut = r_e0 *rate*R_pid_p+ r_ee *rate*R_pid_d;
        if(PidOut<rate*40)
        {
            PidOut = rate*R_pid_min_p;
        }
    }
    if (PidOut > 4095)
        PidOut = 4095;
    if (PidOut < 0)
        PidOut = 0;
    Serial.print("pwm: ");
    Serial.println(PidOut);
    PidE1 = PidE0;
    return PidOut;
}