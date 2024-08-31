#pragma once
#include "trip-meta-data.hpp"
#include "rating-based-pricing-strategy.hpp"
#include "least-time-based-matching-strategy.hpp"
#include "default-pricing-strategy.hpp"
#include "common.hpp"
#include<mutex>

class StrategyManager{
    StrategyManager() {}
    static StrategyManager* strategyMgrInstance;
    static mutex mtx;

    public:
    static StrategyManager* getStrategyMgr();
    PricingStrategy* determinePricingStrategy(TripMetaData* pTripMetaData);
    DriverMatchingStrategy* determineMatchingStrategy(TripMetaData* metaData);
};