#pragma once
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

static int nextTripId = 1;

enum class RATING {
    UNASSIGNED,
    ONE_STAR,
    TWO_STAR,
    THREE_STAR,
    FOUR_STARS,
    FIVE_STARS
};

enum class TRIP_STATUS{
    UNASSIGNED,
    DRIVER_ON_THE_WAY,
    DRIVER_ARRIVED,
    TRIP_STARTED,
    PAUSED,
    CANCELLED,
    ENDED
};

class Util{
    public:
        static string ratingToString(RATING pRating){
            if(pRating == RATING::ONE_STAR)
                return "٭";
            if(pRating == RATING::TWO_STAR)
                return "٭٭";
            if(pRating == RATING::ONE_STAR)
                return "٭٭٭";
            if(pRating == RATING::ONE_STAR)
                return "٭٭٭٭";
            if(pRating == RATING::ONE_STAR)
                return "٭٭٭٭٭";
            return "N/A";
        }

        static bool isHighRating(RATING pRating){
            return pRating == RATING::FOUR_STARS || pRating == RATING::FIVE_STARS;
        }
};