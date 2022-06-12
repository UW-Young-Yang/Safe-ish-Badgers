// Name: Young Yang
// WiscID: xyang532
#include "menus.h"
using namespace std;

int main() {
    int main_menu, testing_menu, reservation_menu, checker_menu, user_menu, settings_menu, number;
    bool main_loop = true;
    User user;
    LocationList testing_location;
    testing_location.FromFile("locations.txt");
    // testing_location.AddLocation(Location("Kohl Center, Gate C", "601 W Dayton St", "8:30am-4:30pm", true));
    // testing_location.AddLocation(Location("Dejope Hall, 1165", "640 Elm Dr", "9:30am-5:30pm", true));
    // testing_location.AddLocation(Location("21 N Park St, 1106", "21 N Park St", "7:30am-3:30pm", false));
    // testing_location.AddLocation(Location("Shell, 110", "1430 Monroe St", "8:30am-4:30pm", false));
    // testing_location.AddLocation(Location("Mechanical Engineering Building, 1184", "1513 University Ave", "6:30am-2:30pm", true));
    string symptoms[] = {
        "Fever",
        "Cough",
        "Shortness of breath",
        "Loss of taste or smell",
        "Fatigue",
        "Sore throat"}
    ;
    int size_of_symptoms = sizeof(symptoms) / sizeof(symptoms[0]);
    bool selected[size_of_symptoms];
    // initialize boolean array
    for (int i = 0; i < size_of_symptoms; i++) {
        selected[i] = false;
    }

    while (main_loop)
    {
        bool loop = true;
        printMainMenu();
        cin >> main_menu;

        switch (main_menu)
        {
        case 1:
            while (true) {
                testing_location.Sort(user.AveragePosition());
                printTestingLocations(testing_location);
                cin >> testing_menu;
                if (testing_menu == testing_location.GetCount() + 1) {
                    break;
                } else if (1 <= testing_menu && testing_menu <= testing_location.GetCount()) {
                    int index = testing_menu - 1;
                    testing_location.GetLocation(index)-> Print();
                    cin.get();
                    cin.clear();
                    cin.ignore(1024, '\n');
                    break;
                } else {
                    cout << "\nYou need to enter a number that exists in the menu, " \
                            "please try again.\n";
                    cin.clear();
                    cin.ignore(1024, '\n');
                }
            }
            break;
        case 2:
            while (true) {
                testing_location.Sort(user.AveragePosition());
                printReservationLocations(testing_location);
                cin >> reservation_menu;
                if (reservation_menu == testing_location.GetCount() + 1) {
                    break;
                } else if (1 <= reservation_menu && reservation_menu <= testing_location.GetCount()) {
                    // if it is not reservable
                    Location* location = testing_location.GetLocation(reservation_menu-1);
                    if (!location -> IsReservable()) {
                        cout << "\nYou need to enter a number that exists in the menu, " \
                          "please try again.\n";
                        continue;
                    }
                    location -> Reserve();
                    user.MakeReservation(*location);
                    cin.clear();
                    cin.ignore(1024, '\n');
                    break;
                } else {
                    cout << "\nYou need to enter a number that exists in the menu, " \
                            "please try again.\n";
                    cin.clear();
                    cin.ignore(1024, '\n');
                }
            }
            break;
        case 3:
            while (true) {
                printSymptomChecker(symptoms, selected);
                cin >> checker_menu;
                if (1 <= checker_menu && checker_menu <= size_of_symptoms) {
                    int index = checker_menu - 1;
                    selected[index] = selected[index] ? false : true;
                } else if (checker_menu == size_of_symptoms + 1) {
                    int number_of_selected = 0;
                    for (int i = 0; i < size_of_symptoms; i++) {
                        if (selected[i]) number_of_selected++;
                    }
                    if (number_of_selected == 0) {
                        cout << "\nYou seem to be feeling fine. Remember to test " \
                            "regularly for Covid-19.\n";
                    } else if (number_of_selected < 3) {
                        cout << "\nPlease stay home and monitor your symptoms. If " \
                            "your symptoms persist or you develop new symptoms,\nplease " \
                            "go to an available testing site to be tested for Covid-19.\n";
                    } else {
                        cout << "\nPlease go to an available testing site to be tested " \
                            "for Covid-19.\n";
                    }
                    cout << "Press enter to return to main menu.\n";
                    cin.get();
                    cin.clear();
                    cin.ignore(1024, '\n');
                    break;
                } else if (checker_menu == size_of_symptoms + 2) {
                    break;
                } else {
                    cout << "\nYou need to enter a number that exists in the menu, " \
                            "please try again.\n";
                    cin.clear();
                    cin.ignore(1024, '\n');
                }
            }
            break;
        case 4:
            number = user.CheckExposures();
            if (number > 0) {
                cout << "Found " << number << " possible Covid-19 exposures, please arrange to be tested for Covid-19.\n";
            } else if (number == 0) {
                cout << "No Covid-19 exposures detected!.\n";
            } else {
                cout << "Error number: " << number << endl;
            }
            cout << "\nPress enter to return to main menu.\n";
            cin.get();
            cin.clear();
            cin.ignore(1024, '\n');
            break;
        case 5:
            user.PrintReservations();
            std::cin.get();
            std::cin.clear();
            std::cin.ignore(1024, '\n');
            break;
        case 6:
            user.PrintData();
            // cin.fail();
            std::cin.get();
            std::cin.clear();
            std::cin.ignore(1024, '\n');
            break;
        case 7:
            while (loop) {
                printUserDataMenu(user);
                cin >> user_menu;
                switch (user_menu) {
                    case 1:
                        while(true) {
                            cout << "\nPlease enter your first name: \n";
                            cin >> user.first_name;
                            if (cin.good()) {
                                break;
                            } else {
                                cout << "\nThe name you enter must be string, " \
                                    "please try again.\n";
                                cin.clear();
                                cin.ignore(1024, '\n');
                            }
                        }
                        break;
                    case 2:
                        while(true) {
                            cout << "\nPlease enter your last name: \n";
                            cin >> user.last_name;
                            if (cin.good()) {
                                break;
                            } else {
                                cout << "\nThe name you enter must be string, " \
                                    "please try again.\n";
                                cin.clear();
                                cin.ignore(1024, '\n');
                            }
                        }
                        break;
                    case 3:
                        while(true) {
                            cout << "\nPlease enter your age: \n";
                            cin >> user.age;
                            if (cin.good()) {
                                cin.clear();
                                cin.ignore(1024, '\n');
                                if (user.age < 0) {
                                    cout << "\nYour age shouldn't be a negative number, " \
                                        "please try again.\n";
                                } else if (user.age > 122) {
                                    cout << "\nThe age you enter should not exceed 122, "
                                        "please try again.\n";
                                } else {
                                    break;
                                }
                            } else {
                                cout << "\nThe age you enter must be a number, " \
                                    "please try again.\n";
                                cin.clear();
                                cin.ignore(1024, '\n');
                            }
                        }
                        break;
                    case 4:
                        while(true) {
                            cout << "\nPlease enter your height(" << user.heightUnit.substr(1) << \
                                "): \n";
                            cin >> user.height;
                            if (cin.good()) {
                                if (user.height < 0) {
                                    cout << "\nYour height shouldn't be a negative number, " \
                                        "please try again.\n";
                                } else if (user.height > ((user.is_metric) ? 2.75 : 9)) {
                                    cout << "\nThe height you enter should not exceed" \
                                        " 9ft/2.75m, please try again.\n";
                                } else {
                                    break;
                                }
                            } else {
                                cout << "\nThe height you enter must be a number, " \
                                    "please try again.\n";
                                cin.clear();
                                cin.ignore(1024, '\n');
                            }
                        }
                        break;
                    case 5:
                        while(true) {
                            cout << "\nPlease enter your weight(" << user.weightUnit.substr(1) << \
                                "): \n";
                            cin >> user.weight;
                            if (cin.good()) {
                                if (user.weight < 0) {
                                    cout << "\nYour weight shouldn't be a negative number, " \
                                        "please try again.\n";
                                } else if (user.weight > ((user.is_metric) ? 445 : 975)) {
                                    cout << "\nThe weight you enter should not exceed" \
                                        " 975lbs/445kg, please try again.\n";
                                } else {
                                    break;
                                }
                            } else {
                                cout << "\nThe height you enter must be a number, " \
                                    "please try again.\n";
                                cin.clear();
                                cin.ignore(1024, '\n');
                            }
                        }
                        break;
                    case 6:
                        loop = false;
                        break;
                    default:
                        cout << "\nYou need to enter a number that exists in the menu, " \
                            "please try again.\n";
                        cin.clear();
                        cin.ignore(1024, '\n');
                        break;
                }
            }
            break;
        case 8:
            while (true) {
                printSettingsMenu(user.is_metric);
                cin >> settings_menu;
                if (settings_menu == 1) {
                    user.SwitchUnits();
                } else if (settings_menu == 2) {
                    std::string last_name;
                    cout << "Please enter your last name:\n";
                    cin.get();
                    getline(cin, last_name, '\n');
                    if (cin.good()) {
                        bool is_imperial = true;
                        std::string fname = last_name != "" ? last_name + ".txt" : "";
                        user.Read(is_imperial, fname);
                    } else {
                        cout << "\nThe name you enter must be string, " \
                            "please try again.\n";
                        cin.clear();
                        cin.ignore(1024, '\n');
                    }
                } else if (settings_menu == 3) {
                    user.Write(true);
                } else if (settings_menu == 4) {

                } else {
                    cout << "\nYou need to enter a number that exists in the menu, " \
                        "please try again.\n";
                    cin.clear();
                    cin.ignore(1024, '\n');
                    continue;
                }
                break;
            }
            break;
        case 9:
            user.Write(true);
            testing_location.ToFile("locations.txt");
            cout << "\nThanks for using Safe-ish Badgers!\nBye!\n";
            main_loop = false;
            break;
        default:
            cout << "\nYou need to enter a number that exists in the menu, " \
                        "please try again.\n";
            cin.clear();
            cin.ignore(1024, '\n');
            break;
        }
    }
}