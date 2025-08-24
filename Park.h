#ifndef PARK_H
#define PARK_H



#include "CityEntity.h"

class Park : virtual public CityEntity {
protected:
    bool hasTrees;

public:
    Park(const string& n, int z, bool trees)
        : CityEntity(n, z), hasTrees(trees) {}

    virtual ~Park() {}

    string getType() const override {
        return "Park";
    }
};

#endif