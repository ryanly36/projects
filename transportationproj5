#ifndef RIVERSEGMENT_H
#define RIVERSEGMENT_H

#include "TransportationLink.h"
#include <iostream>
#include <vector>

using namespace std;

class RiverSegment : public TransportationLink {
    private: 
        vector<double> scheduledDepartureTimes;
        double _speed;
    public:
        RiverSegment(const string &name, double speed, double distance);
        void setSpeed(double speed);
        void addDepartureTime(double hour);
        unsigned computeArrivalTime(unsigned minute) const;
    
};
#endif
