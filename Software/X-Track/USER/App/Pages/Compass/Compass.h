#ifndef __COMPASS_H
#define __COMPASS_H

#include "CompassModel.h"
#include "CompassView.h"
#include "App/Utils/PageManager/PageBase.h"

namespace Page {
class Compass : public PageBase {
public:
    Compass();
    virtual ~Compass();
protected:
    virtual void onViewLoad();
    virtual void onViewDidAppear();

private:
    CompassModel Model;
    CompassView View;
    static void onTimer(lv_timer_t* timer);
    static void onEvent(lv_event_t* event);
};
}

#endif
