#ifndef BUS_H
#define BUS_H
#include "CityEntity.h"
class BusStop :virtual public CityEntity {
    protected:
    bool hasShelter;

    public:
    BusStop(const string& name,int zone, bool Shelter):
    CityEntity(name,zone), hasShelter(Shelter) {}
    virtual ~BusStop() {}
    string getType() const override {
        return "BusStop";
    }
};



#endif