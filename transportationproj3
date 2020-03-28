#include "RiverSegment.h"

using namespace std;

RiverSegment::RiverSegment(const string &name, double speed, double distance) : TransportationLink(name, distance), _speed(speed)  
{
//     for(unsigned i = 0; i < 24; ++i) {
//         scheduledDepartureTimes.push_back(_speed);
//     }
}

void RiverSegment::setSpeed(double speed) {
    _speed = speed;
}

void RiverSegment::addDepartureTime(double hour) {

    scheduledDepartureTimes.push_back(hour);
//     cout << "sadness: " << scheduledDepartureTimes.size() << endl;
//     for(unsigned i = 0; i < scheduledDepartureTimes.size(); ++i) {
//         cout << scheduledDepartureTimes.at(i) << endl;
//     }
    
    for(unsigned i = 0; i < scheduledDepartureTimes.size()-1; ++i) {
        double minIndex = i;
        for(unsigned k = i+1; k < scheduledDepartureTimes.size(); ++k) {
            if(scheduledDepartureTimes.at(k) < scheduledDepartureTimes.at(minIndex)) {
                minIndex = k;
    
            }
        }
        double temp = scheduledDepartureTimes.at(i);
        scheduledDepartureTimes.at(i) = scheduledDepartureTimes.at(minIndex);
        scheduledDepartureTimes.at(minIndex) = temp;
    }
    
//     for(unsigned i = 0; i < scheduledDepartureTimes.size(); ++i) {
//          if(scheduledDepartureTimes.at(i) != scheduledDepartureTimes.size()-1){
//             if(scheduledDepartureTimes.at(i) < hour && scheduledDepartureTimes.at(i+1) > hour) {
//                 scheduledDepartureTimes.insert(scheduledDepartureTimes.begin()+i,1 ,hour);
//                 cout << "inserted time: " << scheduledDepartureTimes.at(i) << endl;
//             break;
//             }
//          }
//         else {
//             scheduledDepartureTimes.insert(scheduledDepartureTimes.begin()+i,hour);
//             break;

//         }
//     }
//     cout << "out of for loop" << endl;
//     for(unsigned i = 0; i < scheduledDepartureTimes.size(); ++i) { for loop to test selection sort
//         cout << scheduledDepartureTimes.at(i);
//     }
}


unsigned RiverSegment::computeArrivalTime(unsigned minute) const {
//     for(unsigned i = 0; i < scheduledDepartureTimes.size(); ++i) {
//         cout << scheduledDepartureTimes.at(i) << endl;
//     }
    int departureTime;
    unsigned arrivalTime;
     int hour = minute / 60;
//     cout << "size of vector: " << scheduledDepartureTimes.size() << endl;
    //cout << "minutes: " << minute << endl;
     //cout << "departure time hour: " << hour << endl;
    for(unsigned i = 0; i <scheduledDepartureTimes.size(); ++i) {
        if(scheduledDepartureTimes.at(i) > hour) {
            departureTime = scheduledDepartureTimes.at(i)*60;
            //cout << "departure time: " <<departureTime << endl;
            break;
        }
        if(minute/60 > scheduledDepartureTimes.at(scheduledDepartureTimes.size()-1)) {
            departureTime = scheduledDepartureTimes.at(0) + 60 * 24;
        }
        else{
            departureTime = scheduledDepartureTimes.at(scheduledDepartureTimes.size()-1)*60;
        }
    }
    arrivalTime = (_distance / _speed) * 60 + departureTime;
    
    return arrivalTime;
}
