/*
 * Copyright 2024 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"
extern float PidE1;
extern float pid_p;
extern float pid_i;
extern float pid_d;
extern float R_pid_p;
extern float R_pid_d;
extern float R_pid_min_p;
extern int rate;
extern float target_temperature;
extern float voltage;
extern float electric_current;
extern float power;
extern float current_temperature;
extern uint8_t display_id;
extern unsigned long per_endtime;
extern bool over;
void events_init(lv_ui *ui)
{
}

static void screen_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_t *act_scr = lv_scr_act();
		lv_disp_t *d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.screen_2_del == true)
				setup_scr_screen_2(&guider_ui);
			lv_scr_load_anim(guider_ui.screen_2, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 100, 100, true);
			guider_ui.screen_del = true;
		}
	}
	break;
	default:
		break;
	}
}

static void screen_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_t *act_scr = lv_scr_act();
		lv_disp_t *d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.screen_1_del == true)
				setup_scr_screen_1(&guider_ui);
			lv_scr_load_anim(guider_ui.screen_1, LV_SCR_LOAD_ANIM_OVER_TOP, 100, 100, true);
			guider_ui.screen_del = true;
			display_id = 1;
		}
	}
	break;
	default:
		break;
	}
}

static void screen_btn_12_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_t *act_scr = lv_scr_act();
		lv_disp_t *d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.screen_2_del == true)
				setup_scr_screen_2(&guider_ui);
			lv_scr_load_anim(guider_ui.screen_2, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 100, 100, true);
			guider_ui.screen_del = true;
			display_id = 2;
		}
	}
	break;
	default:
		break;
	}
}

static void screen_btn_13_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_t *act_scr = lv_scr_act();
		lv_disp_t *d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.screen_3_del == true)
				setup_scr_screen_3(&guider_ui);
			lv_scr_load_anim(guider_ui.screen_3, LV_SCR_LOAD_ANIM_FADE_ON, 100, 100, true);
			guider_ui.screen_del = true;
			display_id = 3;
		}
	}
	break;
	default:
		break;
	}
}

void events_init_screen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen, screen_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_btn_1, screen_btn_1_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_btn_12, screen_btn_12_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_btn_13, screen_btn_13_event_handler, LV_EVENT_ALL, ui);
}

static void screen_1_btn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_t *act_scr = lv_scr_act();
		lv_disp_t *d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.screen_del == true)
				setup_scr_screen(&guider_ui);
			lv_scr_load_anim(guider_ui.screen, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 100, 100, true);
			guider_ui.screen_1_del = true;
			display_id = 0;
		}
	}
	break;
	default:
		break;
	}
}

static void screen_1_btn_11_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		over = false;
		// per_endtime = 1000 * 60 * (target_temperature - current_temperature) / rate;
		if (rate < 70)
			rate++;
		lv_label_set_text_fmt(guider_ui.screen_1_label_11, "Rate: %dC/min", rate);
	}
	break;
	default:
		break;
	}
}

static void screen_1_btn_12_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		over = false;
		// per_endtime = 1000 * 60 * (target_temperature - current_temperature) / rate;
		if (rate > 1)
			rate--;
		lv_label_set_text_fmt(guider_ui.screen_1_label_11, "Rate: %dC/min", rate);
	}
	break;
	default:
		break;
	}
}

static void screen_1_btn_13_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		PidE1 = 0.0f;
		over = false;
		if (target_temperature < 100)
			target_temperature++;
		lv_label_set_text_fmt(guider_ui.screen_1_label_9, "Target :%.2fC", target_temperature);
	}
	break;
	default:
		break;
	}
}

static void screen_1_btn_14_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		PidE1 = 0.0f;
		over = false;
		if (target_temperature > 20)
			target_temperature--;
		lv_label_set_text_fmt(guider_ui.screen_1_label_9, "Target :%.2fC", target_temperature);
	}
	break;
	default:
		break;
	}
}

void events_init_screen_1(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_1_btn_2, screen_1_btn_2_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_1_btn_11, screen_1_btn_11_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_1_btn_12, screen_1_btn_12_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_1_btn_13, screen_1_btn_13_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_1_btn_14, screen_1_btn_14_event_handler, LV_EVENT_ALL, ui);
}

static void screen_2_btn_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_t *act_scr = lv_scr_act();
		lv_disp_t *d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.screen_del == true)
				setup_scr_screen(&guider_ui);
			lv_scr_load_anim(guider_ui.screen, LV_SCR_LOAD_ANIM_MOVE_TOP, 100, 100, true);
			guider_ui.screen_2_del = true;
			display_id = 0;
		}
	}
	break;
	default:
		break;
	}
}

static void screen_2_btn_5_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
			R_pid_p--;
		lv_label_set_text_fmt(guider_ui.screen_2_label_3, "Rate_P:%.0f", R_pid_p);
	}
	break;
	default:
		break;
	}
}

static void screen_2_btn_6_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
			R_pid_p++;
		lv_label_set_text_fmt(guider_ui.screen_2_label_3, "Rate_P:%.0f", R_pid_p);
	}
	break;
	default:
		break;
	}
}

static void screen_2_btn_7_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
			R_pid_d++;
		lv_label_set_text_fmt(guider_ui.screen_2_label_4, "Rate_d:%.0f", R_pid_d);
	}
	break;
	default:
		break;
	}
}

static void screen_2_btn_8_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
			R_pid_d--;
		lv_label_set_text_fmt(guider_ui.screen_2_label_4, "Rate_d:%.0f", R_pid_d);
	}
	break;
	default:
		break;
	}
}

static void screen_2_btn_9_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		R_pid_min_p++;
		lv_label_set_text_fmt(guider_ui.screen_2_label_5, "Rate_min:%.0f", R_pid_min_p);
	}
	break;
	default:
		break;
	}
}

static void screen_2_btn_10_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (R_pid_min_p > 0)
			R_pid_min_p--;
		lv_label_set_text_fmt(guider_ui.screen_2_label_5, "Rate_min:%.0f", R_pid_min_p);
	}
	break;
	default:
		break;
	}
}

void events_init_screen_2(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_2_btn_3, screen_2_btn_3_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_2_btn_5, screen_2_btn_5_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_2_btn_6, screen_2_btn_6_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_2_btn_7, screen_2_btn_7_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_2_btn_8, screen_2_btn_8_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_2_btn_9, screen_2_btn_9_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_2_btn_10, screen_2_btn_10_event_handler, LV_EVENT_ALL, ui);
}

static void screen_3_btn_14_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_t *act_scr = lv_scr_act();
		lv_disp_t *d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.screen_del == true)
				setup_scr_screen(&guider_ui);
			lv_scr_load_anim(guider_ui.screen, LV_SCR_LOAD_ANIM_MOVE_LEFT, 100, 100, true);
			guider_ui.screen_3_del = true;
			display_id = 0;
		}
	}
	break;
	default:
		break;
	}
}

void events_init_screen_3(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_3_btn_14, screen_3_btn_14_event_handler, LV_EVENT_ALL, ui);
}
