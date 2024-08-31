#pragma once
#include "trip-meta-data.hpp"
#include "driver-mgr.hpp"

class DriverMatchingStrategy{
    public:
    virtual Driver* matchDriver(TripMetaData* pTripMetaData) = 0;
};