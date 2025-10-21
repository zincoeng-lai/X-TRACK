#ifndef __COMPASS_MODEL_H
#define __COMPASS_MODEL_H

#include "Common/DataProc/DataProc.h"

namespace Page {
class CompassModel {
public:
    void Init();
    void Deinit();
    void GetMAGInfo(float* dir,int* x,int* y,int* z);
    void GetArrowTheme(char* buf, uint32_t size);

private:
    Account* account;
};
}

#endif
