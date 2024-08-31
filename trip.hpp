#include "rider.hpp"
#include "driver.hpp"
#include "location.hpp"
#include "pricing-strategy.hpp"
#include "driver-matching-strategy.hpp"

class Trip{
    Rider* rider;
    Driver* driver;
    Location* srcLoc;
    Location* destLoc;
    TRIP_STATUS status;
    int tripId;
    double price;
    PricingStrategy* pricingStrategy;
    DriverMatchingStrategy* driverMatchingStrategy;

    public:
    Trip(Rider* pRider, Driver* pDriver, Location* pSrcLoc, Location* pDestLoc, double pPrice, PricingStrategy* pPricingStrategy, DriverMatchingStrategy* pDriverMatchingStrategy):
        rider(pRider), driver(pDriver), srcLoc(pSrcLoc), destLoc(pDestLoc), price(pPrice), pricingStrategy(pPricingStrategy), driverMatchingStrategy(pDriverMatchingStrategy){
            status = TRIP_STATUS::DRIVER_ON_THE_WAY;
            tripId = nextTripId;
            nextTripId++;
        }

    int getTripId(){
        return tripId;
    }

    void displayTripDetails(){
        cout<<endl;
        cout<<"Trip Id: "<<tripId<<endl;
        cout<<"Rider: "<<rider->getRiderName()<<endl;
        cout<<"Driver: "<<driver->getDriverName()<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Locations: ("<<srcLoc->latitude<<", "<<srcLoc->longitude<<") and ("<<destLoc->latitude<<", "<<destLoc->longitude<<endl;
    }
};