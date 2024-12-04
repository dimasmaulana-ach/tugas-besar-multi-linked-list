//
// Created by Dimas Maulana Ahmad on 03/12/24.
//

#ifndef STRUCTURE_H
#define STRUCTURE_H

#endif //STRUCTURE_H

#include <iostream>
#include <string>

using namespace std;


// Define
#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info

// =================
// Driver (SLL)
// =================

struct Driver {
    int id;
    string name;
    string phone;
    string vehiclePlate;
    string status; // active , inactive
    Driver* next;
};

// DriverList

struct DriverList {
    Driver* head;
};
// =================
// Customer
// =================

struct Customer {
    int id;
    string name;
    string phone;
    string address;
    Customer* next;
    Customer* prev;
};

// typedef
typedef Customer CustomerInfotype;
typedef struct elmCustomer* CustomerAddress;

struct elmCustomer {
    CustomerInfotype info;
    CustomerAddress next;
    CustomerAddress prev;
};

struct listCustomer {
  CustomerAddress first;
  CustomerAddress last;
};

// =================
// Relation (Order)
// =================

struct Relation {
    Driver* driver;
    Customer* customer;
    Relation* next;
    Relation* prev;
};

// typedef
typedef Relation RelationInfotype;
typedef struct elmRelation* RelationAddress;

struct elmRelation {
    RelationInfotype info;
    RelationAddress next;
    RelationAddress prev;
};

struct listRelation {
  RelationAddress first;
  RelationAddress last;
};


// Create List


/**
 * ====================================================================================================
 * Define Kelas Driver
 * ====================================================================================================
 */

class DriverClass {
public:
    DriverClass();

    Driver* createElementDriver(DriverList data);

    void insertDriver(DriverList &Ld, Driver D); // Define Insert Driver -> As a Insert Last

    void deleteDriver(DriverList &Ld, listRelation &Lr, int Id); // Delete Driver

    Driver* findDriver(DriverList &Ld, int driverId); // Cari Driver

    void displayDrivers(DriverList &Ld); // Tampilkan List Driver

    int countOrdersPerDriver(listRelation Lr, string driverId ); // Validate and Check Count Order of Driver

    ~DriverClass();
};