#include "../../lv_examples.h"
#if LV_USE_CHART && LV_BUILD_EXAMPLES 
lv_obj_t * chart;
lv_chart_series_t *ser1;
lv_chart_series_t *ser2;
void lv_example_chart_1(void)
{
    /*Create a chart*/
   
    chart = lv_chart_create(lv_scr_act());
    lv_obj_set_size(chart, 200, 150);
    lv_obj_center(chart);
    lv_chart_set_type(chart, LV_CHART_TYPE_LINE);   /*Show lines and points too*/

    /*Add two data series*/
    ser1 = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
    ser2 = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_GREEN), LV_CHART_AXIS_SECONDARY_Y);

    /*Set the next points on 'ser1'*/
    lv_chart_set_next_value(chart, ser1, 10);
    lv_chart_set_next_value(chart, ser1, 20);
    lv_chart_set_next_value(chart, ser1, 30);
    lv_chart_set_next_value(chart, ser1, 40);
    lv_chart_set_next_value(chart, ser1, 50);
    lv_chart_set_next_value(chart, ser1, 60);
    lv_chart_set_next_value(chart, ser1, 70);
    lv_chart_set_next_value(chart, ser1, 80);
    lv_chart_set_next_value(chart, ser1, 90);
    lv_chart_set_next_value(chart, ser1, 100);

    /*Directly set points on 'ser2'*/
    ser2->y_points[0] = 100;
    ser2->y_points[1] = 90;
    ser2->y_points[2] = 80;
    ser2->y_points[3] = 70;
    ser2->y_points[4] = 60;
    ser2->y_points[5] = 50;
    ser2->y_points[6] = 40;
    ser2->y_points[7] = 30;
    ser2->y_points[8] = 20;
    ser2->y_points[9] = 10;

    lv_chart_refresh(chart); /*Required after direct set*/
}
void test(int chart_index,int val[10])
{
    if (chart_index == 1)
    {
    ser1->y_points[0] = val[0];
    ser1->y_points[1] = val[1];
    ser1->y_points[2] = val[2];
    ser1->y_points[3] = val[3];
    ser1->y_points[4] = val[4];
    ser1->y_points[5] = val[5];
    ser1->y_points[6] = val[6];
    ser1->y_points[7] = val[7];
    ser1->y_points[8] = val[8];
    ser1->y_points[9] = val[9];
    }
    else if (chart_index == 2)
    {
        ser2->y_points[0] = val[0];
        ser2->y_points[1] = val[1];
        ser2->y_points[2] = val[2];
        ser2->y_points[3] = val[3];
        ser2->y_points[4] = val[4];
        ser2->y_points[5] = val[5];
        ser2->y_points[6] = val[6];
        ser2->y_points[7] = val[7];
        ser2->y_points[8] = val[8];
        ser2->y_points[9] = val[9];
    }
    lv_chart_refresh(chart);
}
#endif
