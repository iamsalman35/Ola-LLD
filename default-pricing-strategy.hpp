#pragma once
#include "pricing-strategy.hpp"

class DefaultPricingStrategy: public PricingStrategy{
    public:
    double calculatePrice(TripMetaData* pTripMetaData){
        cout<<"Based on Default Pricing Strategy, the calculated price is: 100 INR"<<endl;
        return 100.00;
    }
};