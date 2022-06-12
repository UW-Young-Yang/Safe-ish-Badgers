#ifndef CAMPUS
#define CAMPUS
#include "Location.h"
#include <iomanip>
class CampusLocation : public Location {
    public:
        CampusLocation();
        bool Reserve();
        void Cancel();
        void Print() const;
        void Read(std::istream &s);
        void Write(std::ostream &s);
};
#endif