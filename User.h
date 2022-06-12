#ifndef USER
#define USER
#include "LocationList.h"
struct User {
    std::string first_name, last_name;
    int age;
    float height, weight;
    bool is_metric;
    std::string heightUnit;
    std::string weightUnit;
    LocationList location_list;
    std::string user_filename, reservations_filename, positions_filename;
    std::vector<Position> positions;
    User();
    void MakeReservation(Location &new_reservation);
    void to_string();
    void PrintData();
    void PrintReservations();
    void SwitchUnits();
    void Read(bool &is_imperial, std::string fname = "");
    void Write(const bool is_imperial);
    int CheckExposures();
    Position AveragePosition() const;
};

struct Sum {
    Position sum = Position(0, 0);
    void operator()(Position next);
};
#endif