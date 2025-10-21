#include "Compass.h"

using namespace Page;

Compass::Compass() {}
Compass::~Compass() {}

void Compass::onViewLoad() {
    Model.Init();
    View.Create(_root);
    lv_obj_add_flag(_root, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(_root, onEvent, LV_EVENT_ALL, this);
}

void Compass::onViewDidAppear() {
    lv_group_t* group = lv_group_get_default();
    LV_ASSERT_NULL(group);
    lv_group_add_obj(group, _root);
    lv_timer_t* timer = lv_timer_create(onTimer, 200, this);
}

void Compass::onEvent(lv_event_t* event) {
    Compass* instance = (Compass*)lv_event_get_user_data(event);
    lv_event_code_t code = lv_event_get_code(event);
    if (code == LV_EVENT_PRESSED) {
        instance->_Manager->Pop();
    }
}

void Compass::onTimer(lv_timer_t* timer) {
    Compass* instance = (Compass*)timer->user_data;
    float heading;
    int x, y, z;
    instance->Model.GetMAGInfo(&heading, &x, &y, &z);
    instance->View.UpdateArrow(heading);
}
