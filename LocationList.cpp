#include "LocationList.h"

LocationList::LocationList() {
    Location_arr = std::vector<Location *>();
}

LocationList::~LocationList() {
    for (int i = 0; i < GetCount(); i++) {
        delete Location_arr[i];
    }
}

int LocationList::GetCount() const {
    return Location_arr.size();
}

Location* LocationList::GetLocation(int index) const {
    return Location_arr[index];
}

void LocationList::AddLocation(Location *new_loc) {
    Location_arr.push_back(new_loc);
}

void LocationList::FromFile(std::string fname) {
    std::fstream io_file;
    std::string data;
    io_file.open(fname);
    if (! io_file.is_open()) {
        std::cout << "\nError opening file!\n";
    } else {
        std::getline(io_file, data, '\n');
        int number = std::stoi(data);
        for (int i = 0; i < number; i++) {
            std::getline(io_file, data, '\n');
            if (data == "citylocation") {
                Location *city = new CityLocation();
                city -> Read(io_file);
                AddLocation(city);
            } else {
                CampusLocation *campus = new CampusLocation();
                campus -> Read(io_file);
                AddLocation(campus);
            }
        }
    }
    io_file.close();
}

void LocationList::ToFile(std::string fname) {
    std::fstream io_file(fname, std::fstream::out);
    if(!io_file) {
        std::cout << "\nError opening file!\n";
    } else {
        io_file << GetCount() << std::endl;
        for (int i = 0; i < GetCount(); i++) {
            Location_arr[i] -> Write(io_file);
        }
    }
    io_file.close();
}

LocationList::Closer::Closer(Position p) {
    position = Position(p);
}

bool LocationList::Closer::operator()(Location *a, Location *b) {
    float distance_a = *a - position;
    float distance_b = *b - position;
    if (distance_a < distance_b) {
        return true;
    } else {
        return false;
    }
}

void LocationList::Sort(Position p) {
    Closer compare(p);
    sort(Location_arr.begin(), Location_arr.end(), compare);
}