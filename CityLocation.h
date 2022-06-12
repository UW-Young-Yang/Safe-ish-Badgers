#ifndef CITY
#define CITY
#include "Location.h"
#include <iomanip>
class CityLocation : public Location {
    public:
        CityLocation();
        bool Reserve();
        void Cancel();
        void Print() const;
        void Read(std::istream &s);
        void Write(std::ostream &s);
};
#endif