/* ** Router Simulator ** */
// Purpose: Store clients in "router" objects

/* ** Includes ** */
#include "router.hpp"
#include "client.hpp"

#include <unordered_map>

string Router::Set_Up(const bool stateful, int max_clients, int min_rssi)
{
    // set up
    this->stateful = stateful;
    this->max_clients = max_clients;
    this->min_rssi = min_rssi;
    return "";
}

string Router:: Add(const string &name, const int &rssi, const string &mac_address) {
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