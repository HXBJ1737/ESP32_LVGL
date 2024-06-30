/*
 * Copyright 2024 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"
static lv_obj_t * g_kb_screen_3;
static void kb_screen_3_event_cb(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *kb = lv_event_get_target(e);
	if(code == LV_EVENT_READY || code == LV_EVENT_CANCEL){
		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
}
__attribute__((unused)) static void ta_screen_3_event_cb(lv_event_t *e)
{

	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *ta = lv_event_get_target(e);
	lv_obj_t *kb = lv_event_get_user_data(e);
	if (code == LV_EVENT_FOCUSED || code == LV_EVENT_CLICKED)
	{
		lv_keyboard_set_textarea(kb, ta);
		lv_obj_move_foreground(kb);
		lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
	if (code == LV_EVENT_CANCEL || code == LV_EVENT_DEFOCUSED)
	{
		lv_keyboard_set_textarea(kb, NULL);
		lv_obj_move_background(kb);
		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
}

void setup_scr_screen_3(lv_ui *ui){

	//Write codes screen_3
	ui->screen_3 = lv_obj_create(NULL);

	//Create keyboard on screen_3
	g_kb_screen_3 = lv_keyboard_create(ui->screen_3);
	lv_obj_add_event_cb(g_kb_screen_3, kb_screen_3_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(g_kb_screen_3, LV_OBJ_FLAG_HIDDEN);
	lv_obj_set_style_text_font(g_kb_screen_3, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_scrollbar_mode(ui->screen_3, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_3. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_bg_color(ui->screen_3, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_3, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_3, 251, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_3_btn_14
	ui->screen_3_btn_14 = lv_btn_create(ui->screen_3);
	lv_obj_set_pos(ui->screen_3_btn_14, 1, 1);
	lv_obj_set_size(ui->screen_3_btn_14, 57, 29);
	lv_obj_set_scrollbar_mode(ui->screen_3_btn_14, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_3_btn_14. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_3_btn_14, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_3_btn_14, lv_color_make(0x3d, 0x3d, 0x3d), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_3_btn_14, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_3_btn_14, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_3_btn_14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_3_btn_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_3_btn_14, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_3_btn_14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_3_btn_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_3_btn_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_3_btn_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_3_btn_14, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_3_btn_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_3_btn_14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_3_btn_14, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_3_btn_14, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_3_btn_14, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->screen_3_btn_14_label = lv_label_create(ui->screen_3_btn_14);
	lv_label_set_text(ui->screen_3_btn_14_label, "Back");
	lv_obj_set_style_pad_all(ui->screen_3_btn_14, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->screen_3_btn_14_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes screen_3_label_6
	ui->screen_3_label_6 = lv_label_create(ui->screen_3);
	lv_obj_set_pos(ui->screen_3_label_6, 69, 1);
	lv_obj_set_size(ui->screen_3_label_6, 119, 31);
	lv_obj_set_scrollbar_mode(ui->screen_3_label_6, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_3_label_6, "恒星不见");
	lv_label_set_long_mode(ui->screen_3_label_6, LV_LABEL_LONG_WRAP);

	//Set style for screen_3_label_6. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_3_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_3_label_6, lv_color_make(0x60, 0x60, 0x60), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_3_label_6, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_3_label_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_3_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_3_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_3_label_6, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_3_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_3_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_3_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_3_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_3_label_6, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_3_label_6, &lv_font_chinese_siyuan, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_3_label_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_3_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_3_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_3_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_3_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_3_label_6, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_3_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_3_spangroup_1
	ui->screen_3_spangroup_1 = lv_spangroup_create(ui->screen_3);
	lv_obj_set_pos(ui->screen_3_spangroup_1, 20, 70);
	lv_obj_set_size(ui->screen_3_spangroup_1, 200, 100);
	lv_obj_set_scrollbar_mode(ui->screen_3_spangroup_1, LV_SCROLLBAR_MODE_OFF);
	lv_spangroup_set_align(ui->screen_3_spangroup_1, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_3_spangroup_1, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_3_spangroup_1, LV_SPAN_MODE_BREAK);

	//Set style for screen_3_spangroup_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_3_spangroup_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_3_spangroup_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_3_spangroup_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_3_spangroup_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_3_spangroup_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_3_spangroup_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_3_spangroup_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_3_spangroup_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_3_spangroup_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_3_spangroup_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_3_spangroup_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_3_spangroup_1, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_3_spangroup_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_3_spangroup_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_3_spangroup_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_3_spangroup_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_3_spangroup_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_3_spangroup_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//create spans
	lv_span_t *screen_3_spangroup_1_span;

	//create a new span
	screen_3_spangroup_1_span = lv_spangroup_new_span(ui->screen_3_spangroup_1);
	lv_span_set_text(screen_3_spangroup_1_span, "@copyright Copyright (c) 2024\n");
	lv_style_set_text_color(&screen_3_spangroup_1_span->style, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_decor(&screen_3_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&screen_3_spangroup_1_span->style, &lv_font_montserratMedium_12);

	//create a new span
	screen_3_spangroup_1_span = lv_spangroup_new_span(ui->screen_3_spangroup_1);
	lv_span_set_text(screen_3_spangroup_1_span, "     Issued in 2024.02.17\n");
	lv_style_set_text_color(&screen_3_spangroup_1_span->style, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_decor(&screen_3_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&screen_3_spangroup_1_span->style, &lv_font_montserratMedium_15);
	lv_spangroup_refr_mode(ui->screen_3_spangroup_1);

	//Write codes screen_3_qrcode_1
	ui->screen_3_qrcode_1 = lv_qrcode_create(ui->screen_3, 105, lv_color_make(0x2C, 0x32, 0x24), lv_color_make(0xff, 0xff, 0xff));
	const char * screen_3_qrcode_1_data = "http://esp.hxbj.online";
	lv_qrcode_update(ui->screen_3_qrcode_1, screen_3_qrcode_1_data, strlen(screen_3_qrcode_1_data));
	lv_obj_set_pos(ui->screen_3_qrcode_1, 128, 128);
	lv_obj_set_size(ui->screen_3_qrcode_1, 105, 105);

	//Init events for screen
	events_init_screen_3(ui);
}