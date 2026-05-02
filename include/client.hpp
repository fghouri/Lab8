/* ** Client Header ** */
// Purpose: Structure implementation for client.hpp

/* ** Includes ** */
#include <iostream>

using namespace std;

class Client {
    public:
        // Constructor
        Client(const string &name, const int &rssi, const string &mac_address);
        string getName();
        string getMAC();
        int getRSSI(); 
        void Print_Data();

    private:
        string name;
        string mac_address;
        int rssi;
};
