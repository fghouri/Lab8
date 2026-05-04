/* ** Client Header ** */
// Purpose: Structure implementation for client.hpp

#ifndef CLIENT_HPP
#define CLIENT_HPP

/* ** Includes ** */
#include <iostream>

using namespace std;

class Client {
    public:
        // Constructor
        Client(const string &name, const int &rssi, const string &mac_address);
        string getName() const;
        string getMAC() const;
        int getRSSI() const;
        void Print_Data() const;
        string String_Data();

    private:
        string name;
        string mac_address;
        int rssi;
};
#endif
