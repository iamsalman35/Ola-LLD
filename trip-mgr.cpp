#include "trip-mgr.hpp"

TripManager* TripManager::tripMgrInstance = nullptr;
mutex TripManager::mtx;

TripManager* TripManager::getTripMgr(){
    if(tripMgrInstance == nullptr){
        mtx.lock();
        if(tripMgrInstance == nullptr){
            tripMgrInstance = new TripManager();
        }
        mtx.unlock();
    }
    return tripMgrInstance;
}

void TripManager::CreateTrip(Rider* pRider, Location* pSrcLoc, Location* pDestLoc){
    TripMetaData* metaData = new TripMetaData(pSrcLoc, pDestLoc, pRider->getRating());
    StrategyManager* strategyMgr = StrategyManager::getStrategyMgr();
    PricingStrategy* pricingStrategy = strategyMgr->determinePricingStrategy(metaData);
    DriverMatchingStrategy* driverMatchingStrategy = strategyMgr->determineMatchingStrategy(metaData);

    Driver* driver = driverMatchingStrategy->matchDriver(metaData);
    doble tripPrice = pricingStrategy->calculatePrice(metaData);

    Trip* trip = new Trip(pRider, driver, pSrcLoc, pDestLoc, tripPrice, pricingStrategy, driverMatchingStrategy);
    int tripId = trip->getTripId();
    tripsInfo[tripId] = trip;
    tripsMetaDataInfo[tripId] = metaData;
}

unordered_map<int, Trip*> TripManager::getTripsMap(){

}