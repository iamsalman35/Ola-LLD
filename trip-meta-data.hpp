#pragma once
#include "rider.hpp"
#include "driver.hpp"

class TripMetaData{
    Location *srcLoc;
    Location *destLoc;
    RATING riderRating;
    RATING driverRating;

    public:
        TripMetaData(Location* pSrcLoc, Location* pDestLoc, RATING pRiderRating):
            srcLoc(pSrcLoc), destLoc(pDestLoc), riderRating(pRiderRating) {
                driverRating = RATING::UNASSIGNED;
        }

        RATING getRiderRating(){
            return riderRating;
        }

        RATING getDriverRating(){
            return driverRating;
        }

        void setDriverRating(RATING pDriverRating){
            driverRating = pDriverRating;
        }
};