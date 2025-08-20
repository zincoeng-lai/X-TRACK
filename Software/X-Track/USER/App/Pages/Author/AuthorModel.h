#ifndef __AUTHOR_MODEL_H
#define __AUTHOR_MODEL_H

#include "Common/DataProc/DataProc.h"
#include "Common/HAL/HAL.h"

namespace Page
{

class AuthorModel
{
public:
    void Init();
    void Deinit();
    void PlayMusic(const char* music);
    void SetEncoderEnable(bool en)
    {
        HAL::Encoder_SetEnable(en);
    }
    void SetStatusBarAppear(bool en);

private:
    Account* account;
};

}

#endif
