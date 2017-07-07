#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

class Passenger {
    public:
        Passenger(int number, std::string first_name, std::string last_name);

        int getNumber() const;
        std::string getFullName() const;

    private:
        int _number;
        std::string _first_name, _last_name;
};

#endif // PASSENGER_H
