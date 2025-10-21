#include "CompassView.h"

using namespace Page;

void CompassView::Create(lv_obj_t* root) {
    ui.cont = lv_obj_create(root);
    lv_obj_set_size(ui.cont, 200, 200);
    lv_obj_center(ui.cont);

    // 创建箭头
    ui.arrow = lv_img_create(ui.cont);
    lv_img_set_src(ui.arrow, ResourcePool::GetImage("gps_arrow_default"));
    lv_obj_center(ui.arrow);

    // 创建方向文字
    ui.labelN = lv_label_create(ui.cont);
    lv_label_set_text(ui.labelN, "N");
    lv_obj_align(ui.labelN, LV_ALIGN_TOP_MID, 0, 10);

    ui.labelS = lv_label_create(ui.cont);
    lv_label_set_text(ui.labelS, "S");
    lv_obj_align(ui.labelS, LV_ALIGN_BOTTOM_MID, 0, -10);

    ui.labelE = lv_label_create(ui.cont);
    lv_label_set_text(ui.labelE, "E");
    lv_obj_align(ui.labelE, LV_ALIGN_RIGHT_MID, -10, 0);

    ui.labelW = lv_label_create(ui.cont);
    lv_label_set_text(ui.labelW, "W");
    lv_obj_align(ui.labelW, LV_ALIGN_LEFT_MID, 10, 0);
}

void CompassView::UpdateArrow(float heading) {
    lv_img_set_angle(ui.arrow, heading * 10); // LVGL角度单位为0.1°
}

void CompassView::SetArrowTheme(const char* theme)
{
    char buf[32];
    snprintf(buf, sizeof(buf), "gps_arrow_%s", theme);

    const void* src = ResourcePool::GetImage(buf);

    if (src == nullptr)
    {
        ResourcePool::GetImage("gps_arrow_default");
    }

    lv_img_set_src(ui.arrow, src);
}
