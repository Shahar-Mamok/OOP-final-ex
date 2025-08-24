#include <iostream>
#include <list>
#include <string>
#include "CityEntity.h"
#include "Park.h"
#include "SportFacility.h"
#include "BusStop.h"
#include "GreenChargingStation.h"
#include "CityManager.h"
#include "CityFilter.h"
#include "CircularIterator.h"
#include "CityZone.h"

using namespace std;
void testQuestion1(int& score) {
        CityEntity* p[4];
		p[0] = new Park("Gan Leumi", 1, true);
        p[1] = new SportFacility("Sport Hall", 2, 1000);
        p[2] = new BusStop("Azrieli Stop", 3, true);
        p[3] = new GreenChargingStation("GreenPoint", 4, true, false);
		if(p[3]->getType() ==  string("GreenChargingStation"))
			score += 10;
		else
			cout<<"Q1_1: Error -10"<<endl;
		if(dynamic_cast<SportFacility*>(p[1]))
			score += 10;
		else
			cout<<"Q1_2: Error -10"<<endl;
}

void testQuestion2(int& score) {
    list<CityEntity*> entities = {
       new Park("Gan A", 1, true),
       new BusStop("Stop B", 2, true),
       new SportFacility("Hall C", 2, 500)
    };

        auto filtered = filter(entities, IsInZone(2));
        if (filtered.size() == 2)
			score += 20;
		else cout<<"Q2: Error -20"<<endl;
}

/*void testQuestion3(int& score) {
        list<CityEntity*> entities = {
            new Park("Gan 1", 1, true),
            new BusStop("Stop 2", 2, true),
		new SportFacility("Hall 3", 3, 300)};


        CircularIterator it(entities);
		CircularIterator head = it;
		it++;
		if((*it)->getName() != string("Stop 2"))
			cout << "Error Q3_1: check ++ operator -10"<<endl;
        else score += 10;

		it++;
		it++;
		if(it != head)
			cout << "Error Q3_2: check ++ operator -10"<<endl;
		else score += 10;
}

void testQuestion4(int& score) {
        CityManager manager;
        manager.addEntity(new Park("City Park", 1, true));
        manager.addEntity(new BusStop("Central", 1, true));
        manager.addEntity(new GreenChargingStation("EcoSpot", 2, true, true));
		manager.addEntity(new Park("ScooterPlay", 3, false));
		int parks, sports, stops, greenCharging;
        manager.countEntities(parks, stops, sports,greenCharging);

		if((parks == 2) && (stops == 1) && (sports == 0) && (greenCharging == 1))
			score+=10;
		else cout << "Error Q4_1: check countEntity -10"<<endl;

        CityEntity* ent = manager.findEntityByName("ScooterPlay");
		if(ent->getZone() == 3)
			score+=10;
		else cout << "Error Q4_2: check findEntityByName -10"<<endl;
}

void testQuestion5(int& score) {

        CityZone mainZone("main");
        CityZone* sub1 = new CityZone("north");
        CityZone* sub2 = new CityZone("south");

        mainZone.addSubzone(sub1);
        mainZone.addSubzone(sub2);

        mainZone.addEntity(new Park("Park Main", 1, true));
        sub1->addEntity(new BusStop("Stop A", 1, true));
        sub2->addEntity(new SportFacility("Hall B", 2, 500));

        if (mainZone.countAllEntities() != 3)
            cout<<"Q5_1 - count error -10"<<endl;
		else score+=10;

        CityEntity* found = mainZone.findEntityByName("Stop A");
        if (!found)
			cout<<"Q5_2 - find entity problem -10"<<endl;

		else score += 10;

}*/


int main() {
    int score = 0;

    testQuestion1(score);
     testQuestion2(score);
    // testQuestion3(score);
    // testQuestion4(score);
    // testQuestion5(score);
   
    
    cout << "\nMark for train (only) is: " << score << endl;
    return 0;
}