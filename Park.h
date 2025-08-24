#ifndef PARK_H
#define PARK_H



#include "CityEntity.h"

class Park : virtual public CityEntity {
protected:
    bool hasTrees_;  // field name with underscore to avoid ambiguity

public:
    // Accessor used by predicates
    bool hasTrees() const { return hasTrees_; }

    Park(const string& n, int z, bool trees)
        : CityEntity(n, z), hasTrees_(trees) {}

    virtual ~Park() {}

    string getType() const override { return "Park"; }
};

#endif