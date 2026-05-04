/* ** Router Simulator ** */
// Purpose: Store clients in "router" objects

/* ** Includes ** */
#include "router.hpp"
#include "client.hpp"
#include <unordered_map>

// Purpose: Initializes up the variable for the router
string Router::Set_Up(const bool stateful, int max_clients, int min_rssi)
{
    // set up
    this->stateful = stateful;
    this->max_clients = max_clients;
    this->min_rssi = min_rssi;
    return "";
}

// Purpose: Adds a client to the router
string Router::Add(const string &name, const int &rssi, const string &mac_address) {
    Client client(name, rssi, mac_address);
    
    if(stateful) {
        if(client_table.size() >= this->max_clients) return "Router table full";
        else {
            // returns a pair {iterator, bool success}
            auto result = client_table.insert({mac_address, client});

            // result.second accesses the bool "success" for .insert()
            if(!result.second) return "ERROR: Client already exists";
        }
    }
    else {
        // insert
         // returns a pair {iterator, bool success}
        auto result = client_table.insert({mac_address, client});

        // result.second accesses the bool "success" for .insert()
        if(!result.second) return "ERROR: Client already exists";
    }
    return "";
}

// Purpose: Looks for a client and returns the client object if found, else nullptr
Client* Router::Find(const string &mac_address) {
    auto it = client_table.find(mac_address);

    // iterator at the end would mean it wasn't found
    if(it != client_table.end()) {
        return &it->second;
    }
    else return nullptr; // for error checking return nullptr
}

// Purpose: Prints all the clients in the router
void Router::printAll() {
    // exists
    if(client_table.size() > 0) {
        for(auto it = client_table.begin(); it != client_table.end(); ++it) {
            cout << client_table.bucket(it->first) << endl; // prints out bucket #
            it->second.Print_Data(); // prints name, rssi, mac_address
        }
    }
}