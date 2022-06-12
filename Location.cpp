#include "Location.h"

Location::Location(std::string name, std::string address, std::string hours, int reservation) {
    this -> name = name;
    this -> address = address;
    Location::hours = hours;
    Location::reservation = reservation; // maximum reservation
    Location::counter = reservation;
}

Location::Location(std::string name, std::string address, std::string hours, float x, float y, int reservations) {
    this -> name = name;
    this -> address = address;
    Location::hours = hours;
    position = Position(x, y);
    Location::reservation = reservation; // maximum reservation
    Location::counter = reservation;
}

Location::Location(const Location &copy_from) {
    name = copy_from.name;
    address = copy_from.address;
    hours = copy_from.hours;
    reservation = copy_from.reservation;
    counter = copy_from.counter;
}

bool Location::IsReservable() const {
    return counter;
}

std::string Location::to_string() const {
    return name;
}

float Location::operator-(const Position that) {
    return position - that;
}
// void Location::Print() const {
//     std::cout << "\nLocation: " << name << "\n";
//     std::cout << "Address: " << address << "\n";
//     std::cout << "Hours: " << hours << "\n";
//     std::cout << "Allows Reservations: " << (reservation ? "Yes" : "No") << "\n";
//     std::cout << "Press enter to return to menu.\n";
// }