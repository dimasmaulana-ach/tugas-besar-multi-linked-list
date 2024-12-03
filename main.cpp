//
// Created by Dimas Maulana Ahmad on 03/12/24.
//

#include "MLL.h"
#include <iostream>


int main() {
    DriverList drivers;
    CustomerList customers;
    RelationList relations;

    // Insert some drivers
    drivers.insertDriver(1, "John Doe", "081234567890", "B1234XYZ", "Online");
    drivers.insertDriver(2, "Jane Smith", "081298765432", "B5678ABC", "Offline");

    // Insert some customers
    customers.insertCustomer(1, "Alice", "081987654321", "Jl. Merpati");
    customers.insertCustomer(2, "Bob", "081123456789", "Jl. Kenari");

    // Create relations
    relations.insertRelation(drivers.findDriver(1), customers.findCustomer(1));
    relations.insertRelation(drivers.findDriver(2), customers.findCustomer(2));

    // Display data
    cout << "\nDaftar Driver:\n";
    drivers.displayDrivers();

    cout << "\nDaftar Customer:\n";
    customers.displayCustomers();

    cout << "\nDaftar Relasi:\n";
    relations.displayRelations();

    return 0;
}
Ï