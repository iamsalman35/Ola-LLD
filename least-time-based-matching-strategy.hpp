#pragma once
#include "driver-matching-strategy.hpp"

class LeastTimeMatchBasedMatchingStrategy: public DriverMatchinStrategy {
    public:
    Driver* matchDriver(TripMetaData* pMetaData){
        DriverManager* driverMgr = DriverManager::getDriverManager();

        if((driverMgr->getDriversMap()).size() == 0){
            cout<<"No Drivers found nearby. Please try again later.";
        }
        cout<<"Using QuadTree to see nearest cabs, using driver manager to get details of drivers: ";
        Driver* driver = ((driverMgr->getDriversMap()).begin())->second;
        cout<<"Setting "<<driver->getDriverName()<<" "<<"as your driver."<<endl;
        pMetaData->setDriverRating(driver->getRating());
        return driver;
    }
};