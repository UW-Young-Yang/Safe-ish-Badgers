#include "CampusLocation.h"

CampusLocation::CampusLocation() : Location("None", "None", "None", 0) {}

bool CampusLocation::Reserve() {
    return false;
}

void CampusLocation::Cancel() {}

void CampusLocation::Print() const {
    std::cout << "\n*** On-Campus ***\n";
    std::cout << std::left << std::setw(21) << "Location: " << name << "\n";
    std::cout << std::left << std::setw(21) << "Address: " << address << "\n";
    std::cout << std::left << std::setw(21) << "Hours: " << hours << "\n";
    std::cout << std::left << std::setw(21) << "Position x: " << position.GetX() << "\n";
    std::cout << std::left << std::setw(21) << "Position y: " << position.GetY() << "\n";
    std::cout << std::left << std::setw(21) << "Reservations: " << counter << "\n";
    std::cout << "Press enter to return to menu.\n";
}

void CampusLocation::Read(std::istream &s) {
    std::string location_data;
    const int SIZE = 5;
    std::string split_string[SIZE];
    std::getline(s, location_data, '\n');
    //int start = 0;
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
}

void CampusLocation::Write(std::ostream &s) {
    float x = position.GetX();
    float y = position.GetY();
    s << "campuslocation\n";
    s << name << ", " << address << ", " << hours << ", " << x << ", " << y << std::endl;
}