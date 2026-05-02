/* ** Client Class ** */
// Purpose: Functions implementation for client.hpp

/* ** Includes ** */
#include "../include/client.hpp"
#include <iostream>

/* ** Functions ** */
// Purpose: Instantiate a client object with the given information
Client:: Client(const string &name, const int &rssi, const string &mac_address) {
    this->name = name;
    this->rssi = rssi;
    this->mac_address = mac_address;
}

// Purpose: Prints the client's information
void Client:: Print_Data() {
    cout << "Name: " << getName() << " RSSI: " << getRSSI() << "MAC: " << getMAC() << endl; 
}

// Methods to return private data
string Client:: getName() { return name; }
string Client:: getMAC() { return mac_address; }
int Client:: getRSSI() { return rssi; }