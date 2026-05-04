// Router Header File to define methods and variables for the router hash table
#ifndef ROUTER_HPP
#define ROUTER_HPP

/* ** Includes ** */
#include <iostream>
#include <unordered_map>
#include <string>
#include "client.hpp"
class Router {
    public:
        std::string Set_Up(const bool stateful, int max_clients = 10000, int min_rssi = 0);
        std::string Add(const std::string &name, const int &rssi, const std::string &mac_address);
        std::string Find(const std::string &mac_address);
        void printAll() const;

    protected:
        std::unordered_map<std::string, Client> client_table;
        bool stateful;
        int max_clients;
        int min_rssi;
};

#endif
