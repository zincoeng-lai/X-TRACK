#include "AuthorModel.h"

using namespace Page;

void AuthorModel::Init()
{
    account = new Account("AuthorModel", DataProc::Center(), 0, this);
    account->Subscribe("MusicPlayer");
    account->Subscribe("StatusBar");
}

void AuthorModel::Deinit()
{
    if (account)
    {
        delete account;
        account = nullptr;
    }
}

void AuthorModel::PlayMusic(const char* music)
{
    DataProc::MusicPlayer_Info_t info;
    DATA_PROC_INIT_STRUCT(info);
    info.music = music;
    account->Notify("MusicPlayer", &info, sizeof(info));
}

void AuthorModel::SetStatusBarAppear(bool en)
{
    DataProc::StatusBar_Info_t info;
    DATA_PROC_INIT_STRUCT(info);
    info.cmd = DataProc::STATUS_BAR_CMD_APPEAR;
    info.param.appear = en;
    account->Notify("StatusBar", &info, sizeof(info));
}
