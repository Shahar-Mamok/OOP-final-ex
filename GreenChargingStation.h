#ifndef GREEN_H
#define GREEN_H
#include "BusStop.h"
#include "Park.h"

class GreenChargingStation : public Park, public BusStop {
public:
    GreenChargingStation(const string& n, int z, bool trees, bool shelter)
        : CityEntity(n, z), Park(n, z, trees), BusStop(n, z, shelter) {}

    virtual ~GreenChargingStation() {}

    string getType() const override {
        return "GreenChargingStation";
    }
};

#endif