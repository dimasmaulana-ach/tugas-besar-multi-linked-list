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

// Driver

struct Driver {
    int id;
    string name;
    string phone;
    string vehiclePlate;
    string status;
    Driver* next;
};

// typedef
typedef Driver DriverInfotype;
typedef struct elmDriver *addrDriver;

struct elmDriver {
    DriverInfotype info;
    addrDriver next;
};

struct listDriver {
  addrDriver first;
  addrDriver last;
};

// Customer

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


// Relation (Order)

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
void createListDriver(listDriver &Ld);

/**
 * ====================================================================================================
 * Define Kelas Driver
 * ====================================================================================================
 */

class DriverClass {
private:
    addrDriver head;
public:
    DriverClass();

    addrDriver createElementDriver(DriverInfotype data);

    void insertDriver(listDriver &Ld, addrDriver addr_d); // Define Insert Driver

    void deleteDriver(listDriver &Ld, listRelation &Lr, int driverId); // Delete Driver

    addrDriver findDriver(listDriver &Ld, int driverId); // Cari Driver

    void displayDrivers(listDriver &Ld); // Tampilkan List Driver

    int countOrdersPerDriver(listRelation Lr, string driverId ); // Validate and Check Count Order of Driver

    ~DriverClass();
};