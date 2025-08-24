#ifndef CITYMANAGER_H
#define CITYMANAGER_H

#include <list>
#include <string>
#include "CityEntity.h"

class CityManager {
private:
    // Owns the pointers added via addEntity (deleted in destructor)
    std::list<CityEntity*> entities_;

public:
    CityManager() = default;

    // Delete copy semantics to avoid double delete
    CityManager(const CityManager&) = delete;
    CityManager& operator=(const CityManager&) = delete;

    // Allow move semantics
    CityManager(CityManager&& other) noexcept : entities_(std::move(other.entities_)) {}
    CityManager& operator=(CityManager&& other) noexcept {
        if (this != &other) {
            // free current
            for (auto* e : entities_) delete e;
            entities_.clear();
            // take ownership
            entities_ = std::move(other.entities_);
        }
        return *this;
    }

    ~CityManager() {
        // Free all owned entities
        for (auto* e : entities_) delete e;
    }

    // Add a new entity (takes ownership)
    void addEntity(CityEntity* e) {
        if (e) entities_.push_back(e);
    }

    // Count entities by type using getType()
    void countEntities(int& parks, int& stops, int& sports, int& greenCharging) const {
        parks = stops = sports = greenCharging = 0;
        for (const auto* e : entities_) {
            const std::string t = e->getType();
            if (t == "Park") ++parks;
            else if (t == "BusStop") ++stops;
            else if (t == "SportFacility") ++sports;
            else if (t == "GreenChargingStation") ++greenCharging;
        }
    }

    // Find entity by name; returns nullptr if not found
    CityEntity* findEntityByName(const std::string& name) {
        for (auto* e : entities_) {
            if (e->getName() == name) return e;
        }
        return nullptr;
    }
};

#endif // CITYMANAGER_H
