#include <iostream>
#include <vector>

#include "Passenger.h"

#define PROMPT endl << "> "

using namespace std;

enum {
    MENU_DISPLAYLIST,
    MENU_ADDPASSENGER,
    // TODO : Add here additional menu identifiers
    MENU_QUIT,
    MENU_COUNT
};

int main() {
    const char *menu[] = {
        "Display the list of passengers",
        "Add a passenger",
        // TODO : Add here additional menu items
        "Quit application"
    };
    vector<Passenger> boarding;
    int nextPassengerNumber = 123456789;
    int choice;

    do {
        cout << "Yes, you can:" << endl;
        for(int i = 1; i<=MENU_COUNT; i++) {
            cout << i << ") " << menu[i-1] << endl;
        }
        cout << PROMPT << "So, give me your number (from the menu): ";
        cin >> choice;

        switch(--choice) {
        case MENU_DISPLAYLIST:
            if(boarding.size()==0)  {
                cout << PROMPT << "Still alone ! Be social" << endl << endl;
            }
            else {
                for(vector<Passenger>::iterator it=boarding.begin(); it!=boarding.end(); it++) {
                    cout << endl << "\t- " << it->getFullName() << " #" << it->getNumber();
                }
                cout << PROMPT << "Already " << boarding.size() << " passenger(s) on the flight !" << endl << endl;
            }
            break;
        case MENU_ADDPASSENGER: {
                string first_name, last_name;

                cout << endl;
                cout << "\t- First name: "; cin >> first_name;
                cout << "\t- Last name: "; cin >> last_name;

                Passenger nice_guy(nextPassengerNumber++, first_name, last_name);

                boarding.push_back(nice_guy);
                cout << PROMPT << nice_guy.getFullName() << " successfully created with id #" << nice_guy.getNumber() << endl << endl;
            }
            break;
        // TODO : Add here additional menu management
        case MENU_QUIT:
            cout << PROMPT << "I never can say good bye." << endl;
            break;
        default:
            cout << PROMPT << "Unkown menu item: " << choice << ". Please, stop kidding !" << endl << endl;
        }
    }
    while(choice != MENU_QUIT);
    return 0;
}
