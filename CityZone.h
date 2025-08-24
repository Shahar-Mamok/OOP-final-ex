#ifndef CITYZONE_H
#define CITYZONE_H

#include <string>
#include <vector>
#include <algorithm>
#include "CityEntity.h"

class CityZone {
private:
    std::string name_;
    std::vector<CityZone*> subzones_;      // owns subzones
    std::vector<CityEntity*> entities_;    // owns entities

public:
    // Construct with zone name
    explicit CityZone(const std::string& name) : name_(name) {}

    // Non-copyable to avoid double-free
    CityZone(const CityZone&) = delete;
    CityZone& operator=(const CityZone&) = delete;

    // Movable
    CityZone(CityZone&& other) noexcept
        : name_(std::move(other.name_)),
          subzones_(std::move(other.subzones_)),
          entities_(std::move(other.entities_)) {
        other.subzones_.clear();
        other.entities_.clear();
    }
    CityZone& operator=(CityZone&& other) noexcept {
        if (this != &other) {
            // free current
            for (auto* z : subzones_) delete z;
            for (auto* e : entities_) delete e;
            // take ownership
            name_      = std::move(other.name_);
            subzones_  = std::move(other.subzones_);
            entities_  = std::move(other.entities_);
            other.subzones_.clear();
            other.entities_.clear();
        }
        return *this;
    }

    // Destructor frees owned memory
    ~CityZone() {
        for (auto* z : subzones_) delete z;
        for (auto* e : entities_) delete e;
    }

    // Add a subzone (takes ownership)
    void addSubzone(CityZone* zone) {
        if (zone) subzones_.push_back(zone);
    }

    // Add an entity (takes ownership)
    void addEntity(CityEntity* entity) {
        if (entity) entities_.push_back(entity);
    }

    // Count all entities recursively (this zone + all subzones)
    int countAllEntities() const {
        int total = static_cast<int>(entities_.size());
        for (const auto* z : subzones_) {
            total += z->countAllEntities();
        }
        return total;
    }

    // Find entity by name (recursive search)
    CityEntity* findEntityByName(const std::string& name) const {
        // search in current zone
        for (auto* e : entities_) {
            if (e->getName() == name) return e;
        }
        // recurse into subzones
        for (auto* z : subzones_) {
            if (CityEntity* found = z->findEntityByName(name)) {
                return found;
            }
        }
        return nullptr;
    }
};

#endif // CITYZONE_H
