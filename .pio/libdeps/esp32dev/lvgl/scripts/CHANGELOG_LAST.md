## [v8.3.8](https://github.com/lvgl/lvgl/compare/v8.3.8...v8.3.8) 6 August 2023

### Breaking Changes

### Architectural

### New Features

### Performance

### Fixes

- fix(decoder): fix LV_IMG_CF_ALPHA_8BIT bin file decoder [`4406`](https://github.com/lvgl/lvgl/pull/4406)
- fix(config): fix typo in LV_USE_PERF_MONITOR and LV_USE_MEM_MONITOR [`4403`](https://github.com/lvgl/lvgl/pull/4403)
- fix(attr): refactor LV_ATTRIBUTE_* for function attributes [`4404`](https://github.com/lvgl/lvgl/pull/4404)
- fix(font): fix optimizer issue in  lv_font_fmt_txt.c [`4385`](https://github.com/lvgl/lvgl/pull/4385)

- fix(btnmatrix): Hide button matrix when all buttons hidden [`65f1c93`](https://github.com/lvgl/lvgl/commit/65f1c9305e1b13356010524da4764fe20fe93030)
- fix(obj) prevent hidden objects keeping focus [`375b3b5`](https://github.com/lvgl/lvgl/commit/375b3b5d3ef2ea8c52f971a1bf20998be7940d5e)
- fix(btnmatrix): Fix typo in previous commit! [`29ed7c5`](https://github.com/lvgl/lvgl/commit/29ed7c5717f6cfbca5ce888bf4497221525aae85)
- fix(tabview): fix warning [`223dc1c`](https://github.com/lvgl/lvgl/commit/223dc1cf9d1cad0f40caf244eb435af0871f4153)
- fix(indev): fix warnings when loggin coordinates is enabled [`645006e`](https://github.com/lvgl/lvgl/commit/645006e35195cab3354f34a1a8cbc8c5ed0fdfad)

- fix: use const lv_img_dsc_t * dsc function parameter in lv_img_buf.h/ [`4f102d7`](https://github.com/lvgl/lvgl/commit/4f102d7b6b2e9f9fa68ab7b976d93762107549a4)
- fix(chart): fix lv_chart_get_point_pos_by_id [`f9ffcc9`](https://github.com/lvgl/lvgl/commit/f9ffcc9d8e11beb369dcbab0945ca85eab8f77b2)
- fix(imgbtn): support LV_OBJ_FLAG_CHECKABLE [`385d999`](https://github.com/lvgl/lvgl/commit/385d999a4a8164fcde6ae05f6a5daa5d5c209dd3)

### Examples

### Docs

- docs(disp): metined that rotation rotates the touch coordinates too [`810852b`](https://github.com/lvgl/lvgl/commit/810852b41be5df66fd7b80f8af69f8b579d142ea)

### CI and tests

### Others

- chore(cmsis-pack): prepare for release v8.3.9 [`4424`](https://github.com/lvgl/lvgl/pull/4424)

- demos: add lv_demo_..._close() functions for each demo [`91038a9`](https://github.com/lvgl/lvgl/commit/91038a99e82a2522f693c7cdc77e9e7a672ee9ed)
- chore: format code [`b1bbb95`](https://github.com/lvgl/lvgl/commit/b1bbb95ceb3f4df07a8a1c7c6ea32db49138cc3e)
- chore(music demo) fix formatting [`416b267`](https://github.com/lvgl/lvgl/commit/416b26771bb64d75be5de48ec7c0342ba3736cba)
