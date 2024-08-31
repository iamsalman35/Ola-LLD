#pragma once
#include "driver.hpp"
#include<bits/stdc++.h>
#include<mutex>
using namespace std;

class DriverManager{
    DriverManager() {}
    static DriverManager* driverMgrInstance;
    static mutex mtx;
    unordered_map<string, Driver*> driversMap;

    public:
        static DriverManager* getDriverManager();
        void addDriver(string pDriverName, Driver* pDriver);
        Driver* getDriver(string pDriverName);
        unordered_map<string, Driver*> getDriversMap();
};