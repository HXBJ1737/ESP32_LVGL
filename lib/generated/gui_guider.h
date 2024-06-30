/*
 * Copyright 2024 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "guider_fonts/guider_fonts.h"
#include "lv_qrcode.h"
typedef struct
{
	lv_obj_t *screen;
	bool screen_del;
	lv_obj_t *screen_img_1;
	lv_obj_t *screen_btn_1;
	lv_obj_t *screen_btn_1_label;
	lv_obj_t *screen_label_1;
	lv_obj_t *screen_label_2;
	lv_obj_t *screen_btn_12;
	lv_obj_t *screen_btn_12_label;
	lv_obj_t *screen_btn_13;
	lv_obj_t *screen_btn_13_label;
	lv_obj_t *screen_1;
	bool screen_1_del;
	lv_obj_t *screen_1_btn_2;
	lv_obj_t *screen_1_btn_2_label;
	lv_obj_t *screen_1_chart_1;
	lv_obj_t *screen_1_label_6;
	lv_obj_t *screen_1_label_7;
	lv_obj_t *screen_1_label_8;
	lv_obj_t *screen_1_label_9;
	lv_obj_t *screen_1_label_10;
	lv_obj_t *screen_1_label_11;
	lv_obj_t *screen_1_btn_11;
	lv_obj_t *screen_1_btn_11_label;
	lv_obj_t *screen_1_btn_12;
	lv_obj_t *screen_1_btn_12_label;
	lv_obj_t *screen_1_btn_13;
	lv_obj_t *screen_1_btn_13_label;
	lv_obj_t *screen_1_btn_14;
	lv_obj_t *screen_1_btn_14_label;
	lv_obj_t *screen_1_bar_1;
	lv_obj_t *screen_2;
	bool screen_2_del;
	lv_obj_t *screen_2_btn_3;
	lv_obj_t *screen_2_btn_3_label;
	lv_obj_t *screen_2_label_3;
	lv_obj_t *screen_2_label_4;
	lv_obj_t *screen_2_label_5;
	lv_obj_t *screen_2_btn_5;
	lv_obj_t *screen_2_btn_5_label;
	lv_obj_t *screen_2_btn_6;
	lv_obj_t *screen_2_btn_6_label;
	lv_obj_t *screen_2_btn_7;
	lv_obj_t *screen_2_btn_7_label;
	lv_obj_t *screen_2_btn_8;
	lv_obj_t *screen_2_btn_8_label;
	lv_obj_t *screen_2_btn_9;
	lv_obj_t *screen_2_btn_9_label;
	lv_obj_t *screen_2_btn_10;
	lv_obj_t *screen_2_btn_10_label;
	lv_obj_t *screen_3;
	bool screen_3_del;
	lv_obj_t *screen_3_btn_14;
	lv_obj_t *screen_3_btn_14_label;
	lv_obj_t *screen_3_label_6;
	lv_obj_t *screen_3_spangroup_1;
	lv_obj_t *screen_3_qrcode_1;
	
	lv_chart_series_t *screen_1_chart_1_0;
	lv_chart_series_t *screen_1_chart_1_1;
} lv_ui;

	void ui_init_style(lv_style_t *style);
	void init_scr_del_flag(lv_ui *ui);
	void setup_ui(lv_ui *ui);
	extern lv_ui guider_ui;
	void setup_scr_screen(lv_ui *ui);
	void setup_scr_screen_1(lv_ui *ui);
	void setup_scr_screen_2(lv_ui *ui);
	void setup_scr_screen_3(lv_ui *ui);
	LV_IMG_DECLARE(_1567004357049_alpha_120x194);

#ifdef __cplusplus
}
#endif
#endif