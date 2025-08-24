#ifndef SPORT_H
#define SPORT_H
#include "CityEntity.h"

class SportFacility : public CityEntity {
protected:
    int capacity;

public:
    SportFacility(const string& n, int z, int c)
        : CityEntity(n, z), capacity(c) {}

    virtual ~SportFacility() {}

    string getType() const override {
        return "SportFacility";
    }
};

#endif