#ifndef __COMPASS_VIEW_H
#define __COMPASS_VIEW_H

#include "../Page.h"

namespace Page {
class CompassView {
public:
    struct {
        lv_obj_t* cont;
        lv_obj_t* arrow;
        lv_obj_t* labelN;
        lv_obj_t* labelE;
        lv_obj_t* labelS;
        lv_obj_t* labelW;
    } ui;

    void Create(lv_obj_t* root);
    void UpdateArrow(float heading);
    void SetArrowTheme(const char* theme);
};
}

#endif
