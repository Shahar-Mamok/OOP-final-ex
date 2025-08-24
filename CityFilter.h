#ifndef CITYFILTER_H
#define CITYFILTER_H

#include <list>
#include "CityEntity.h"
#include "BusStop.h"
#include "Park.h"
using std::list;

// Generic filter function: accepts temporary predicates
template<class T, class Predicate>
list<T*> filter(const list<T*>& lst, const Predicate& predicate) {
    list<T*> out;
    for (T* ptr : lst) {
        if (predicate(ptr)) {
            out.push_back(ptr);
        }
    }
    return out;
}

// Predicates

struct IsBusStop {
    template<class U>
    bool operator()(U* p) const {
        return dynamic_cast<BusStop*>(p) != nullptr;
    }
};

struct IsInZone {
    int z;
    explicit IsInZone(int zone) : z(zone) {}
    template<class U>
    bool operator()(U* p) const {
        const CityEntity* ce = dynamic_cast<const CityEntity*>(p);
        return ce && ce->getZone() == z; // requires getter in CityEntity
    }
};

struct IsParkingWithTrees {
    template<class U>
    bool operator()(U* p) const {
        const Park* park = dynamic_cast<const Park*>(p);
        return park && park->hasTrees();  // requires getter in Park
    }
};

#endif
