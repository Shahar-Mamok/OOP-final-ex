#ifndef CITYENTITY_H
#define CITYENTITY_H
#include <string>
using namespace std;
class  CityEntity {
  protected:
    int zone;
    string name;

    public:
    CityEntity(const string& name, int zone):name(name),zone(zone){}
    virtual ~CityEntity(){}
    virtual string getType() const = 0;

    };
#endif