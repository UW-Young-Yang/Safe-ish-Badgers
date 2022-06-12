#include "CityLocation.h"

CityLocation::CityLocation() : Location("None", "None", "None", 1) {}

bool CityLocation::Reserve() {
    if (IsReservable()) {
        counter--;
        return true;
    }
    return false;
}

void CityLocation::Cancel() {
    if (counter + 1 <= reservation) {
        counter++;
    }
}

void CityLocation::Print() const {
    std::cout << "\n*** Off-Campus ***\n";
    std::cout << std::left << std::setw(21) << "Location: " << name << "\n";
    std::cout << std::left << std::setw(21) << "Address: " << address << "\n";
    std::cout << std::left << std::setw(21) << "Hours: " << hours << "\n";
    std::cout << std::left << std::setw(21) << "Position x: " << position.GetX() << "\n";
    std::cout << std::left << std::setw(21) << "Position y: " << position.GetY() << "\n";
    std::cout << std::left << std::setw(21) << "Reservations: " << counter << "\n";
    std::cout << "Press enter to return to menu.\n";
}

void CityLocation::Read(std::istream &s) {
    std::string location_data;
    const int SIZE = 6;
    std::string split_string[SIZE];
    std::getline(s, location_data, '\n');
    for (int i = 0; i < SIZE; i++) {
        int index = location_data.find(',');
        if (index != -1) {
            split_string[i] = location_data.substr(0, index);
            location_data = location_data.substr(index + 2);
        } else {
            split_string[i] = location_data;
        }
    }
    name = split_string[0];
    address = split_string[1];
    hours = split_string[2];
    position = Position(stof(split_string[3]), stof(split_string[4]));
    reservation = stoi(split_string[5]);
    counter = reservation;
}

void CityLocation::Write(std::ostream &s) {
    float x = position.GetX();
    float y = position.GetY();
    s << "citylocation\n";
    s << name << ", " << address << ", " << hours << ", " << x << ", " << y << ", " << counter << std::endl;
}