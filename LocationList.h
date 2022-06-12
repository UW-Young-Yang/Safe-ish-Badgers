#ifndef LOCATIONLIST
#define LOCATIONLIST
#include "CityLocation.h"
#include "CampusLocation.h"
#include <fstream>
#include <vector>
#include <algorithm>
class LocationList {
    std::vector<Location *> Location_arr;
    public:
        LocationList();
        ~LocationList();
        int GetCount() const;
        Location* GetLocation(int index) const;
        void AddLocation(Location *new_loc);
        void FromFile(std::string fname);
        void ToFile(std::string fname);
        class Closer {
            Position position;
            public:
                Closer(Position p);
                bool operator()(Location *a, Location *b);
        };
        void Sort(Position p);
};
#endif