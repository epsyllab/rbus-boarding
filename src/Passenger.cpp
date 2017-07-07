#include "Passenger.h"

Passenger::Passenger(int number, std::string first_name, std::string last_name) {
    _number = number;
    _first_name = first_name;
    _last_name = last_name;
}

int Passenger::getNumber() const {
    return _number;
}

std::string Passenger::getFullName() const {
    return _first_name + " " + _last_name;
}
