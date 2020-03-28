#include "RoadSegment.h"

using namespace std;

RoadSegment::RoadSegment(const string &name, double speed, double distance) : TransportationLink(name, distance), _speed(speed) 
{
    for(unsigned i = 0; i < 24; ++i) {
        hourlySpeeds.push_back(_speed);
    }
}

void RoadSegment::setHourSpeed(unsigned hour, double speed) {
    
    //cout << "hourlySpeeds size: " << hourlySpeeds.size() << endl;
    hourlySpeeds.at(hour) = speed;
}

void RoadSegment::setAllHourSpeeds(const vector<double> &temp) {
    for(unsigned i = 0; i < temp.size(); ++i) {
        hourlySpeeds.at(i) = temp.at(i);
    }
}

unsigned RoadSegment::computeArrivalTime(unsigned minute) const {
    unsigned arrivalTime;
    int hour = minute/60;
    arrivalTime = (_distance / hourlySpeeds.at(hour)) * 60 + minute;
    
    return arrivalTime;    
}
