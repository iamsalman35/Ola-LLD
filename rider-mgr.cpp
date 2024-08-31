#include "rider-mgr.hpp"
RiderManager* RiderManager::RiderMgrInstance = nullptr;
mutex RiderManager::mtx;

RiderManager* RiderManager::getRiderManager(){
    if(RiderMgrInstance == nullptr){
        mtx.lock();
        if(RiderMgrInstance == nullptr){
            RiderMgrInstance = new RiderManager();
        }
        mtx.unlock();
    }
    return RiderMgrInstance;
}

void RiderManager::addRider(string pRiderName, Rider* pRider){
    ridersMap[pRiderName] = pRider;
}

Rider* RiderManager::getRider(string pRiderName){
    return ridersMap[pRiderName];
}