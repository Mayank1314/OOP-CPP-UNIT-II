



#include <iostream>

#include <string>

#include <vector>

using namespace std;


class Vehicle {

protected:

    string registration;

public:

    Vehicle(string reg) : registration(reg) {}

    virtual void display() const = 0;

    virtual ~Vehicle() = default;

};


class Car : public Vehicle {

public:

    Car(string reg) : Vehicle(reg) {}

    void display() const override {

        cout << "Car: " << registration << endl;

    }

};


class Truck : public Vehicle {

public:

    Truck(string reg) : Vehicle(reg) {}

    void display() const override {

        cout << "Truck: " << registration << endl;

    }

};


int main() {

    vector<Vehicle*> fleet;

    fleet.push_back(new Car("MH12AB1234"));

    fleet.push_back(new Truck("MH14XY5678"));


    for (const auto vehicle : fleet) vehicle->display();

    for (auto vehicle : fleet) delete vehicle;

}

