#ifndef __AUTHOR_PRESENTER_H
#define __AUTHOR_PRESENTER_H

#include "AuthorView.h"
#include "AuthorModel.h"

namespace Page
{

class Author : public PageBase
{
public:

public:
    Author();
    virtual ~Author();

    virtual void onCustomAttrConfig();
    virtual void onViewLoad();
    virtual void onViewDidLoad();
    virtual void onViewWillAppear();
    virtual void onViewDidAppear();
    virtual void onViewWillDisappear();
    virtual void onViewDidDisappear();
    virtual void onViewUnload();
    virtual void onViewDidUnload();

private:
    static void onTimer(lv_timer_t* timer);
    static void onEvent(lv_event_t* event);

private:
    AuthorView View;
    AuthorModel Model;
};

}

#endif
