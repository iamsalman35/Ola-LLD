#include "driver-mgr.hpp"
DriverManager *DriverManager::driverMgrInstance = nullptr;
mutex DriverManager::mtx;

DriverManager *DriverManager::getDriverManager(){
    if (driverMgrInstance == nullptr)
    {
        mtx.lock();
        if (driverMgrInstance == nullptr)
        {
            driverMgrInstance = new DriverManager();
        }
        mtx.unlock();
    }
}

void DriverManager::addDriver(string pDriverName, Driver *pDriver)
{
    driversMap[pDriverName] = pDriver;
}

Driver *DriverManager::getDriver(string pDriverName)
{
    return driversMap[pDriverName];
}

unordered_map<string, Driver *> DriverManager::getDriversMap()
{
    return driversMap;
}