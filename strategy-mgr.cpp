#include "strategy-mgr.hpp"

StrategyManager* StrategyManager::strategyMgrInstance == nullptr;
mutex StrategyManager::mtx;

StrategyManager* StrategyManager::getStrategyMgr(){
    if(strategyMgrInstance == nullptr){
        mtx.lock();
        if(strategyMgrInstance == nullptr){
            strategyMgrInstance = new StrategyManager();
        }
        mtx.unlock();
    }
    return strategyMgrInstance;
}

PricingStrategy* determinePricingStrategy(TripMetaData* pTripMetaData){
    cout<<"Based on location and other factors, setting Pricing Strategy as "<<endl;
    return new DefaultPricingStrategy();
}

DriverMatchingStrategy* determineMatchingStrategy(TripMetaData* metaData){
    cout<<"based on location and other factors, setting Driver Matching Strategy as: "<<endl;
    return new LeastTimeMatchBasedMatchingStrategy();
}