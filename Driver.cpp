
#include "Structure.h"
#include <iostream>
#include <string>

using namespace std;

class DriverHandler{

public:

    int handleRequestDriver (
        DriverList &Ld
    ) {
        int choice;
        Driver* driver;

        do {
            cout << "Driver Information" << endl;
            cout << "1. Add Driver" << endl;
            cout << "2. Delete Driver" << endl;
            cout << "3. Display Driver" << endl;
            cout << "4. Find Driver" << endl;
            cout << "5. Count Orders Per Driver" << endl;
            cout << "6. Exit" << endl;

            // Handle Input Request
            cout << "Choose: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    cout << "Add Driver" << endl;
                    driver->id = rand();
                    cin >> driver->name;
                    cin >> driver->phone;
                    cin >> driver->vehiclePlate;
                    cin >> driver->status;
                    insertDriver(Ld, *driver);
                    break;
                }
                case 2: {
                    break;
                }
                case 3: {
                    break;
                }
                case 4: {
                    break;
                }
                case 5: {
                    break;
                }
                case 6: {
                    return 0;
                }
            }
        } while (choice != 6);

        return 0;
    }

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

    // Delete Driver
    void deleteDriver(DriverList &Ld, listRelation &Lr, int Id) {
        // TODO: Need Implementation
    }

    // Find Driver(Find By ID)
    Driver* findDrivers(DriverList &Ld, int Id) {
        if (Ld.head == nullptr) return  nullptr;

        Driver* driver = Ld.head;
        while (driver != nullptr) {
            if (driver->id == Id) {
                return driver;
            }
            driver = driver->next;
        }

        return driver;
    }

    // Display Driver (List)
    void displayDriver(DriverList &Ld) {
        Driver* temp = Ld.head;
        if(temp == nullptr) cout << "No Driver Available" << endl;
        else {
            while (temp != nullptr) {
                cout << "ID: " << temp->id << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Phone: " << temp->phone << endl;
                cout << "Vehicle Plate: " << temp->vehiclePlate << endl;
                cout << "Status: " << temp->status << endl;
                cout << "=================================" << endl;
            }
        }
    }

    int countOrdersPerDriver(DriverList &Ld) {
        // TODO: Need Impl
    }


};



