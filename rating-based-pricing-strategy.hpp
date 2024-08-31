#pragma once
#include "pricing-strategy.hpp"
#include "common.hpp"
class RatingBasedPricingStrategy: public PricingStrategy{
    public:
    double calculatePrice(TripMetaData* pTripMetaData){
        double price = Util::isHighRating(pTripMetaData->getRiderRating())? 95.0: 99.0;
        cout<<"Based on "<<Util::ratingToString(pTripMetaData->getRiderRating()) << "Rider Raing, price of the Trip is: "<<price<<endl;
        return price;
    }
};