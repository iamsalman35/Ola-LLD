#include "trip-mgr.hpp"

int main(){
    Rider* rider1 = new Rider("Salman Asif", RATING::THREE_STAR);
    Rider* rider2 = new Rider('Tarunima Sarkar', RATING::FIVE_STARS);
    RiderManager* riderMgr = RiderManager::getRiderManager();
    riderMgr->addRider('Salman Asif', rider1); 
    riderMgr->addRider('Tarunima Sarkar', rider2);

    Driver* driver1 = new Driver('Praveen S', RATING::FOUR_STARS);
    Driver* driver2 = new Driver('Shweta B', RATING::FIVE_STARS);
    DriverManager* driverMgr = DriverManager::getDriverManager();
    driverMgr->addDriver('Praveen S', driver1);
    driverMgr->addDriver('Shweta B', driver2);

    TripManager* tripMgr = TripManager::getTripMgr();
    cout<<endl<<"Craeting Trip for Salman Asif from location(10, 10) to location(30, 30)"<<endl;
    tripMgr->CreateTrip(rider1, new Location(10, 10), new Location(30, 30));

    cout<<endl<<"Craeting Trip for Tarunima Sarkar from location(22, 22) to location(30, 30)"<<endl;
    tripMgr->CreateTrip(rider2, new Location(10, 10), new Location(30, 30));

    unordered_map<int, Trip*> tripsMap = tripMgr->getTripsMap();
    for(auto mapVal: tripsMap){
        (mapVal->second)->displayTripDetails();
    }
    return 0;
}