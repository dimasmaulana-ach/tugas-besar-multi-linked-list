
#include "Structure.h"
#include <iostream>
#include <string>

using namespace std;

class DriverHandler{

public:

    // Create List Driver
    void createListDriver(DriverList &Ld) {
        Ld.head = nullptr;
    }

    // Initial element driver
    Driver* createElementDriver(Driver data) {
        Driver* newDriver = new Driver;
        newDriver->id = data.id;
        newDriver->name = data.name;
        newDriver->phone = data.phone;
        newDriver->vehiclePlate = data.vehiclePlate;
        newDriver->status = data.status;
        newDriver->next = nullptr;

        return newDriver;
    }

    // Insert Last
    void insertDriver(DriverList &Ld, Driver D) {
        Driver* newDriver = createElementDriver(D);
        if(Ld.head == nullptr) {
            Ld.head = newDriver;
        } else {
            Driver* temp = Ld.head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newDriver;
        }
    };

};



