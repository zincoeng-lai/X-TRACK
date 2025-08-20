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
    Model.SetEncoderEnable(false);
    View.Create(_root);
    lv_timer_t* timer = lv_timer_create(onTimer, 5000, this);
    lv_timer_set_repeat_count(timer, 1);
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
    lv_obj_fade_out(_root, 500, 1500);
}

void Author::onViewWillDisappear()
{

}

void Author::onViewDidDisappear()
{
    Model.SetStatusBarAppear(true);
}

void Author::onViewUnload()
{
    View.Delete();
    Model.SetEncoderEnable(true);
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

    lv_obj_t* obj = lv_event_get_current_target(event);
    lv_event_code_t code = lv_event_get_code(event);

    if (obj == instance->_root)
    {
        if (code == LV_EVENT_LEAVE)
        {
            //instance->Manager->Pop();
        }
    }
}
