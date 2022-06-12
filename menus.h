#ifndef MENUS
#define MENUS
#include "User.h"
void printMainMenu();
void printTestingLocations(const LocationList &locations);
void printSymptomChecker(std::string symptoms[], bool selected[]);
void printUserDataMenu(const User &user);
void printSettingsMenu(const bool is_metric);
void printReservationLocations(const LocationList& locations);
#endif