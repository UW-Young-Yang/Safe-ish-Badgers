#ifndef LOCATION
#define LOCATION
#include <iostream>
#include <string>
#include "Position.h"
class Location {
    protected:
        std::string name, address, hours;
        int reservation, counter;
        Position position;
        Location(std::string name, std::string address, std::string hours, float x, float y, int reservations);
    public:
        Location(std::string name, std::string address, std::string hours, int reservation);
        Location(const Location &copy_from);
        bool IsReservable() const;
        std::string to_string() const;
        virtual void Print() const = 0;
        virtual void Read(std::istream &s) = 0;
        virtual void Write(std::ostream &s)  = 0;
        virtual bool Reserve() = 0;
        virtual void Cancel() = 0;
        float operator-(const Position that);
};
#endif