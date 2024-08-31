#pragma once
#include "rider.hpp"
#include<bits/stdc++.h>
#include<mutex>
using namespace std;

class RiderManager{
    RiderManager(){}
    static RiderManager* RiderMgrInstance;
    static mutex mtx;
    unordered_map<string, Rider*> ridersMap;

    public:
        static RiderManager* getRiderManager();
        void addRider(string pRiderName, Rider* pRider);
        Rider* getRider(string pRiderName);
};