// Router Header File to define methods and variables for the router hash table

/* ** Includes ** */
#include <iostream>
#include <unordered_map>

class Router {
    public:
        string Set_Up(const bool stateful, int max_clients = 10000, int min_rssi = 0);
        string Add(const string &name, const int &rssi, const string &mac_address);
        string Find(const string &mac_address);
        void printAll() const;
    
    protected: 
        unordered_map<string, Client> client_table;
        bool stateful;
        int max_clients;
        int min_rssi;
};