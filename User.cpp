#include "User.h"

User::User() {
    first_name = "John";
    last_name = "Doe";
    age = 32;
    height = 6.1;
    weight = 201.5;
    is_metric = false; // using ft and lbs by default
    heightUnit = " ft";
    weightUnit = " lbs";
    user_filename = "default.txt";
    reservations_filename = "default_reservations.txt";
    positions_filename = "default_positions.txt";
    positions = std::vector<Position>();
}

void User::MakeReservation(Location& new_reservation) {
    location_list.AddLocation(&new_reservation);
}

void User::to_string() {
    std::cout << first_name + ' ' + last_name << std::endl;
}

void User::PrintData() {
    std::cout << "\nYour data:";
    std::cout << "\nName:   " << first_name + ' ' + last_name;
    std::cout << "\nAge:    " << age;
    std::cout << "\nHeight: " << height << heightUnit;
    std::cout << "\nWeight: " << weight << weightUnit;
    std::cout << "\nPress enter to return to main menu.\n";
}

void User::PrintReservations() {
    std::cout << "\nHere are your reservations:\n";
    for (int i = 0; i < location_list.GetCount(); i++) {
        std::cout << "\n" << location_list.GetLocation(i) -> to_string();
    }
    std::cout << "\n\nPress enter to return to main menu.\n";
}

void User::SwitchUnits() {
    if (is_metric) {
        is_metric = false;
        height *= 3.28;
        weight *= 2.20;
        heightUnit = " ft";
        weightUnit = " lbs";
        std::cout << "\nSuccessfully converted unit to feet and pounds!\n";
    } else {
        is_metric = true;
        height /= 3.28;
        weight /= 2.20;
        heightUnit = " m";
        weightUnit = " kg";
        std::cout << "\nSuccessfully converted unit to meter and kilogram!\n";
    }
}

void User::Read(bool &is_imperial, std::string fname) {
    if (fname == "") {
        fname = user_filename;
    }
    std::fstream io_file(fname);
    if (!io_file) {
        std::cout << "\nError opening file!\n";
    } else {
        int data;
        io_file >> first_name;
        io_file >> last_name;
        io_file >> age;
        io_file >> height;
        io_file >> weight;
        io_file >> data;
        is_metric = data ? false : true;
        if (last_name != "Doe") {
            user_filename = last_name + ".txt";
            reservations_filename = last_name + "_reservations.txt";
            positions_filename = last_name + "_positions.txt";
        }
        location_list.FromFile(reservations_filename);
        std::fstream positions_file(positions_filename);
        if (!positions_file) {
            std::cout << "\nError opening file!\n";
        } else {
            for (int i = 0; i < 24; i++) {
                Position new_position;
                new_position.Read(positions_file);
                positions.push_back(new_position);
            }
        }
        std::cout << "\nSuccessfully load the data from " + fname << std::endl;
    }
}

void User::Write(const bool is_imperial) {
    if (last_name != "Doe") {
        user_filename = last_name + ".txt";
        reservations_filename = last_name + "_reservations.txt";
    }
    std::fstream io_file(user_filename, std::fstream::out);
    if (!io_file) {
        std::cout << "\nError opening file!\n";
    } else {
        io_file << first_name << " " << last_name << " " << age << " " << height << " " << weight << " " << (is_metric ? 0 : 1) << " \n";
        io_file.close();
    }
    location_list.ToFile(reservations_filename);
    std::cout << "\nSuccessfully save the data into " + (last_name != "Doe" ? last_name + ".txt" : "default.txt") << std::endl;
}

int User::CheckExposures() {
    std::fstream io_file("databases.txt");
    std::string data;
    int number = 0;
    if (!io_file) {
        std::cout << "\nError opening file!\n";
        return -1;
    } else {
        std::getline(io_file, data, '\n');
        int number = std::stoi(data);
        for (int i = 0; i < number; i++) {
            for (int j = 0; j < 24; j++) {
                Position new_position;
                new_position.Read(io_file);
                int distance = positions[j] - new_position;
                if (distance < 6) {
                    number++;
                }
            }
            std::getline(io_file, data, '\n'); // skip the line contained "***"
        }
    }
    return number;
}

void Sum::operator()(Position next) {
    sum =  sum + next;
}

Position User::AveragePosition() const {
    Sum result = std::for_each(positions.begin(), positions.end(), Sum());
    return result.sum / 24;
}