#include "MLL.h"

#include <iostream>
#include <string>

using namespace std;

// Implementation Using Single Linked List
DriverList::DriverList() : head(nullptr) {}

void DriverList::insertDriver(int id, string name, string phone, string vehiclePlate, string status) {
    Driver* newDriver = new Driver(id, name, phone, vehiclePlate, status);
    if (head == nullptr) {
        head = newDriver;
    } else {
        Driver* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newDriver;
    }
}

void DriverList::deleteDriver(int id) {
    Driver* temp = head;
    if (temp->id == id) {
        head = temp->next;
        delete temp;
    } else {
        while (temp->next != nullptr && temp->next->id != id) {
            temp = temp->next;
        }
        if (temp->next != nullptr) {
            Driver* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
        }
    }
}

Driver* DriverList::findDriver(int id) {
    Driver* temp = head;
    while (temp != nullptr && temp->id != id) {
        temp = temp->next;
    }
    return temp;
}

void DriverList::displayDrivers() {
    Driver* temp = head;
    while (temp != nullptr) {
        cout << "ID: " << temp->id << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Phone: " << temp->phone << endl;
        cout << "Vehicle Plate: " << temp->vehiclePlate << endl;
        cout << "Status: " << temp->status << endl;
        cout << endl;
        temp = temp->next;
    }
}

int DriverList::countRelationsPerDriver(Driver* driver, Relation* relationHead) {
    int count = 0;
    Relation* temp = relationHead;
    while (temp != nullptr) {
        if (temp->driver == driver) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

DriverList::~DriverList() {
    Driver* temp = head;
    while (temp != nullptr) {
        Driver* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
}


