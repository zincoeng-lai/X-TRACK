#include "Author.h"

using namespace Page;

Author::Author()
{
}

Author::~Author()
{

}

void Author::onCustomAttrConfig()
{
    SetCustomCacheEnable(false);
    SetCustomLoadAnimType(PageManager::LOAD_ANIM_NONE);
}

void Author::onViewLoad()
{
    Model.Init();
    Model.SetEncoderEnable(true);
    View.Create(_root);
    lv_obj_add_flag(_root, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(_root, onEvent, LV_EVENT_ALL, this);
}

void Author::onViewDidLoad()
{
}

void Author::onViewWillAppear()
{
    // Model.PlayMusic("Author");
    lv_anim_timeline_start(View.ui.anim_timeline);
}

void Author::onViewDidAppear()
{
    lv_group_t* group = lv_group_get_default();
    LV_ASSERT_NULL(group);
    lv_group_add_obj(group, _root);
}

void Author::onViewWillDisappear()
{
    lv_obj_fade_out(_root, 300, 1000);
}

void Author::onViewDidDisappear()
{
    // Model.SetStatusBarAppear(true);
}

void Author::onViewUnload()
{
    View.Delete();
    Model.Deinit();
}

void Author::onViewDidUnload()
{
}

void Author::onTimer(lv_timer_t* timer)
{
    Author* instance = (Author*)timer->user_data;

    instance->_Manager->Replace("Pages/Dialplate");
}

void Author::onEvent(lv_event_t* event)
{
    Author* instance = (Author*)lv_event_get_user_data(event);
    LV_ASSERT_NULL(instance);

    lv_event_code_t code = lv_event_get_code(event);

    if (code == LV_EVENT_PRESSED)
    {
        instance->_Manager->Replace("Pages/Dialplate");
    }
}
