#include "menus.h"
#include <iomanip>

void printMainMenu() {
    std::cout << "\nWelcome (back) to Safe-ish Badgers!\n[1] View testing locations\n" \
      "[2] Make test reservation\n[3] Use symptom checker\n[4] Check for Covid-19 Exposures\n" \
      "[5] View my reservations\n[6] View my personal data\n[7] Adjust my personal data\n" \
      "[8] Change settings\n[9] Exit program\nPlease enter a menu item:\n";
}

void printTestingLocations(const LocationList &locations) {
    std::cout << "\nTesting Locations:\n";
    for (int i = 0; i < locations.GetCount(); i++) {
        std::cout << "[" << i + 1 << "] " << locations.GetLocation(i) -> to_string() << "\n";
    }
    std::cout << "[" << locations.GetCount() + 1 << "] Return to main menu\n";
    std::cout << "Choose a location for more information, or return to the menu:\n";
}

void printSymptomChecker(std::string symptoms[], bool selected[]) {
    // int count = sizeof(symptoms) / sizeof(symptoms[0]);
    int count = 6;
    std::cout << "\nSelect Your Symptoms:\n";
    for (int i = 0; i < count; i++) {
        if (selected[i] == true) {
            std::cout << "[" << i + 1 << std::left << std::setw(4) << 
              "*]" << symptoms[i] << "\n";
        } else {
            std::cout << "[" << i + 1 << std::left << std::setw(4) << 
              "]" << symptoms[i] << "\n";
        }
    }
    std::cout << "[" << count + 1 << std::left << std::setw(4) << 
      "]" << "Submit Symptoms\n";
    std::cout << "[" << count + 2 << std::left << std::setw(4) << 
      "]" << "Cancel and return to main menu\n";
}

void printUserDataMenu(const User &user) {
    std::cout << "\nSet your personal data:\n[1] First name (" << user.first_name << \
      ")\n[2] Last name (" << user.last_name << ")\n[3] Age (" << user.age << ")\n" \
      "[4] Height (" << user.height << user.heightUnit << ")\n" \
      "[5] Weight (" << user.weight << user.weightUnit << ")\n[6] Return to main menu\n" \
      "Please enter a menu item:\n";
}

void printSettingsMenu(const bool is_metric) {
    std::cout << "\nChange your app settings:\n[1] Switch units (" << \
      (is_metric ? "metric" : "imperial") << ")\n" \
      "[2] Load Data\n" << \
      "[3] Save Data\n" << \
      "[4] Return to main menu\nPlease enter a menu item:\n";
}

void printReservationLocations(const LocationList& locations){
    std::cout << "\nTesting Locations:\n";
    for (int i = 0; i < locations.GetCount(); i++) {
        if (locations.GetLocation(i) -> IsReservable()) {
            std::cout << "[" << i + 1 << "] " << locations.GetLocation(i) -> to_string() << "\n";
        }
    }
    std::cout << "[" << locations.GetCount() + 1 << "] Return to main menu\n";
    std::cout << "Choose a location to reserve, or return to the menu:\n";
}