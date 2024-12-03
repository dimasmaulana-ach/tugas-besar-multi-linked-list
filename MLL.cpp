//
// Created by Dimas Maulana Ahmad on 03/12/24.
//

#include "MLL.h"

#include <iostream>
#include <string>

using namespace std;

// Node untuk Parent (Driver)
struct Driver {
    int id;               // ID unik Driver
    string name;          // Nama Driver
    string phone;         // Nomor Telepon
    string vehiclePlate;  // Plat Nomor Kendaraan
    string status;        // Status (Online/Offline)
    Driver* next;         // Pointer ke node berikutnya

    Driver(int id, string name, string phone, string vehiclePlate, string status)
        : id(id), name(name), phone(phone), vehiclePlate(vehiclePlate), status(status), next(nullptr) {}
};

// Node untuk Child (Customer)
struct Customer {
    int id;              // ID unik Customer
    string name;         // Nama Customer
    string phone;        // Nomor Telepon
    string address;      // Alamat Customer
    Customer* next;      // Pointer ke node berikutnya

    Customer(int id, string name, string phone, string address)
        : id(id), name(name), phone(phone), address(address), next(nullptr) {}
};

// Node untuk Relasi (Order)
struct Relation {
    Driver* driver;      // Pointer ke driver
    Customer* customer;  // Pointer ke customer
    Relation* next;      // Pointer ke relasi berikutnya

    Relation(Driver* driver, Customer* customer)
        : driver(driver), customer(customer), next(nullptr) {}
};

// Single Linked List untuk Parent (Driver)
class DriverList {
private:
    Driver* head;

public:
    DriverList() : head(nullptr) {}

    void insertDriver(int id, string name, string phone, string vehiclePlate, string status) {
        Driver* newDriver = new Driver(id, name, phone, vehiclePlate, status);
        if (!head) {
            head = newDriver;
        } else {
            Driver* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newDriver;
        }
        cout << "Driver dengan ID " << id << " berhasil ditambahkan.\n";
    }

    Driver* findDriver(int id) {
        Driver* temp = head;
        while (temp) {
            if (temp->id == id) return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    void displayDrivers() {
        Driver* temp = head;
        while (temp) {
            cout << "ID: " << temp->id << ", Nama: " << temp->name << ", Status: " << temp->status << "\n";
            temp = temp->next;
        }
    }

    ~DriverList() {
        while (head) {
            Driver* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Single Linked List untuk Child (Customer)
class CustomerList {
private:
    Customer* head;

public:
    CustomerList() : head(nullptr) {}

    void insertCustomer(int id, string name, string phone, string address) {
        Customer* newCustomer = new Customer(id, name, phone, address);
        if (!head) {
            head = newCustomer;
        } else {
            Customer* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newCustomer;
        }
        cout << "Customer dengan ID " << id << " berhasil ditambahkan.\n";
    }

    Customer* findCustomer(int id) {
        Customer* temp = head;
        while (temp) {
            if (temp->id == id) return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    void displayCustomers() {
        Customer* temp = head;
        while (temp) {
            cout << "ID: " << temp->id << ", Nama: " << temp->name << ", Alamat: " << temp->address << "\n";
            temp = temp->next;
        }
    }

    ~CustomerList() {
        while (head) {
            Customer* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Single Linked List untuk Relasi (Order)
class RelationList {
private:
    Relation* head;

public:
    RelationList() : head(nullptr) {}

    void insertRelation(Driver* driver, Customer* customer) {
        if (!driver || !customer) {
            cout << "Driver atau Customer tidak ditemukan.\n";
            return;
        }
        Relation* newRelation = new Relation(driver, customer);
        if (!head) {
            head = newRelation;
        } else {
            Relation* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newRelation;
        }
        cout << "Relasi antara Driver ID " << driver->id << " dan Customer ID " << customer->id << " berhasil ditambahkan.\n";
    }

    void displayRelations() {
        Relation* temp = head;
        while (temp) {
            cout << "Driver: " << temp->driver->name << " - Customer: " << temp->customer->name << "\n";
            temp = temp->next;
        }
    }

    ~RelationList() {
        while (head) {
            Relation* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
