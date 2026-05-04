/* ** Client Class ** */
// Purpose: Functions implementation for client.hpp

/* ** Includes ** */
#include "client.hpp"
#include <iostream>
#include <string>
/* ** Functions ** */
// Purpose: Instantiate a client object with the given information
Client:: Client(const string &name, const int &rssi, const string &mac_address) {
    this->name = name;
    this->rssi = rssi;
    this->mac_address = mac_address;
}

// Purpose: Prints the client's information
void Client:: Print_Data() const {
    cout << "Name: " << getName() << " RSSI: " << getRSSI() << "MAC: " << getMAC() << endl;
}

std::string Client:: String_Data() {
    string s = "Name: " + getName() + " RSSI: " + std::to_string(getRSSI()) + " MAC: " + getMAC() + "\n";
    return s;
}

// Methods to return private data
string Client:: getName() const { return name; }
string Client:: getMAC() const { return mac_address; }
int Client:: getRSSI() const { return rssi; }
