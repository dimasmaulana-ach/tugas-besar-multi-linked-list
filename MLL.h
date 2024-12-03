#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

// Node untuk Parent (Driver)
struct Driver {
    int id;
    string name;
    string phone;
    string vehiclePlate;
    string status;
    Driver* next;

    Driver(int id, string name, string phone, string vehiclePlate, string status)
        : id(id), name(name), phone(phone), vehiclePlate(vehiclePlate), status(status), next(nullptr) {}
};

// Node untuk Child (Customer)
struct Customer {
    int id;
    string name;
    string phone;
    string address;
    Customer* next;

    Customer(int id, string name, string phone, string address)
        : id(id), name(name), phone(phone), address(address), next(nullptr) {}
};

// Node untuk Relasi (Order)
struct Relation {
    Driver* driver;
    Customer* customer;
    Relation* next;

    Relation(Driver* driver, Customer* customer)
        : driver(driver), customer(customer), next(nullptr) {}
};

// Kelas untuk mengelola daftar Driver (Parent)
class DriverList {
private:
    Driver* head;

public:
    DriverList();
    void insertDriver(int id, string name, string phone, string vehiclePlate, string status); // a
    void deleteDriver(int id); // d
    Driver* findDriver(int id); // g
    void displayDrivers(); // j
    int countRelationsPerDriver(Driver* driver); // p
    ~DriverList();
};

// Kelas untuk mengelola daftar Customer (Child)
class CustomerList {
private:
    Customer* head;

public:
    CustomerList();
    void insertCustomer(int id, string name, string phone, string address); // b
    void deleteCustomer(int id); // e
    Customer* findCustomer(int id); // h
    void displayCustomers(); // k
    int countRelationsPerCustomer(Customer* customer); // q
    int countUnrelatedCustomers(Relation* relationHead); // r
    ~CustomerList();
};

// Kelas untuk mengelola daftar Relasi (Order)
class RelationList {
private:
    Relation* head;

public:
    RelationList();
    void insertRelation(Driver* driver, Customer* customer); // c
    void deleteRelation(Driver* driver, Customer* customer); // f
    Relation* findRelation(Driver* driver, Customer* customer); // i
    void displayRelations(); // m
    void displayChildFromParent(Driver* driver); // l
    void displayParentFromChild(Customer* customer); // o
    void editRelation(Driver* driver, Customer* oldCustomer, Customer* newCustomer); // s
    ~RelationList();
};

#endif // MLL_H
