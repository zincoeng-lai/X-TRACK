#include "CompassModel.h"

using namespace Page;

void CompassModel::Init() {
    account = new Account("CompassModel", DataProc::Center(), 0, this);

    account->Subscribe("SportStatus");
    account->Subscribe("GPS");
    account->Subscribe("MAG");
    account->Subscribe("IMU");
    account->Subscribe("Clock");
    account->Subscribe("Power");
    account->Subscribe("Storage");
    account->Subscribe("StatusBar");
}

void CompassModel::Deinit() {
    if (account)
    {
        delete account;
        account = nullptr;
    }
}

void CompassModel::GetMAGInfo(float* dir,int* x,int* y,int* z)
{
    HAL::MAG_Info_t mag = { 0 };
    account->Pull("MAG", &mag, sizeof(mag));
    *x = mag.x;
    *y = mag.y;
    *z = mag.z;

    HAL::GPS_Info_t gps = { 0 };
    account->Pull("GPS", &gps, sizeof(gps));
    *dir = gps.course;
}

void CompassModel::GetArrowTheme(char* buf, uint32_t size)
{
    DataProc::SysConfig_Info_t sysConfig;
    if(account->Pull("SysConfig", &sysConfig, sizeof(sysConfig)) != Account::RES_OK)
    {
        buf[0] = '\0';
        return;
    }
    strncpy(buf, sysConfig.arrowTheme, size);
    buf[size - 1] = '\0';
}
