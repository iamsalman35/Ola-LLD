#pragma once
#include "rider-mgr.hpp"
#include "driver-mgr.hpp"
#include "trip-meta-data.hpp"
#include "trip.hpp"
#include "strategy-mgr.hpp"

class TripManager{
    static TripManager* tripMgrInstance;
    static mutex mtx;

    RiderManager* riderMgr;
    DriverManager* driverMgr;
    unordered_map<int, TripMetaData*> tripsMetaDataInfo;
    unordered_map<int, Trip*> tripsInfo;

    TripManager(){
        riderMgr = RiderManager::getRiderManager();
        driverMgr= DriverManager::getDriverManager();
    }

    public:
    static TripManager* getTripMgr();
    void CreateTrip(Rider* pRider, Location* pSrcLoc, Location* pDestLoc);
    unordered_map<int, Trip*> getTripsMap();
};