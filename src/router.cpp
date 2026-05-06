/* ** Router Simulator ** */
// Purpose: Store clients in "router" objects

/* ** Includes ** */
#include "router.hpp"
#include "client.hpp"

#include <string>
#include <unordered_map>
#include <sstream>

// Purpose: Sets router initial state based on ./ initialization
string Router::Set_Up(const bool stateful, int max_clients, int min_rssi)
{
    // set up
    this->stateful = stateful;
    this->max_clients = max_clients;
    this->min_rssi = min_rssi;
    return "";
}
// Purpose: Prints the current state of router 
void Router::Print_State() const {
    cout << "____________________________________" << endl;
    cout << "|              Router              |" << endl;
    cout << "------------------------------------" << endl;
    // left-justify the labels and set a width of 15 for alignment
    cout << "| State:       " << (stateful ? "Stateful" : "Stateless") << endl;
    cout << "| Max Clients: " << max_clients << endl;
    cout << "| Min RSSI:    " << min_rssi << endl;
    cout << "------------------------------------" << endl;
}

// Purpose: Handles stateful and stateless inserts into client table. Handles pre-existing
string Router:: Add(const string &name, const int &rssi, const string &mac_address) {
    Client client(name, rssi, mac_address);

    if(stateful) {
        if(static_cast<int>(client_table.size()) >= this->max_clients) return "Router table full";
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
// Purpose: Looks for a client and returns string of private variables, else empty string
string Router::Find(const string &mac_address) const {
    auto it = client_table.find(mac_address);
    // iterator at the end would mean it wasn't found
    if(it != client_table.end()) {
        std::ostringstream ss;
        ss << "  __________________________" << "\n"
       << "  |        Client          |" << "\n"
       << "  | Name: " << std::setw(17) << std::left << it->second.getName() << "|" << "\n"
       << "  | RSSI: " << std::setw(17) << std::left << it->second.getRSSI() << "|" << "\n"
       << "  | MAC:  " << std::setw(17) << std::left << it->second.getMAC()  << "|" << "\n"
       << "  --------------------------";
        return ss.str();
    }
    else return ""; // for error checking return nullptr
}

// Purpose: Prints all the clients in the router
void Router::printAll() const {
    // exists
    Print_State();

    std::cout << "\nCONNECTED CLIENTS:\n";
    if (client_table.empty()) {
        std::cout << "  (No clients currently connected)\n";
        return;
    }

    // Range-based for loop works exactly the same for unordered_map
    for (const auto& pair : client_table) {
        // pair.first is the MAC address (key)
        // pair.second is the Client object (value)
        std::cout << Find(pair.first) << "\n\n";
    }
}
