#pragma once
#include "trip-meta-data.hpp"

class PricingStrategy{
    public:
        virtual double calculatePrice(TripMetaData* pTripMetaData) = 0;
};