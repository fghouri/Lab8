/**********************************************************
* router_tester.cpp
* Interface for interaction with router and clients within
* Usage: ./router_tester <state> <max_clients> <min_rssi>
**********************************************************/

// This file runs the interface for the router allowing lookup, additions, deletions, and state instantiation via user input
// Example setup prompt usage: router_tester state(stateful/stateless) if stateful grab components max_clients min_rssi


#include "router.hpp"
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

// Helper function for Help query
void print_commands()
{
  cout << "A key val      Add the given key/val pair to the router's client table.\n";
  cout << "F key          Find the given key in the hash table.\n";
  cout << "P              Print the router's client table.\n";
  cout << "Q              Quit.\n";
  cout << "?              Print commands.\n";
}

// Main Interface setup and loop
int main(int argc, char **argv)
{
  // Set up init Vars
  string name, prompt, mac_address;
  Router router;
  int max_clients =1000;
  int min_rssi = 0;
  int rssi;

  // Set up helper vars
  string t, line;        // read new line append to vector sv
  vector <string> sv;
  istringstream ss;

  try {
    /* take instantiation input and do light error checking  */

    if (argc != 2 && argc !=4) throw((string) "");
    prompt = (argc == 5) ? argv[2]: "";
    if (prompt.size() > 0 && prompt[prompt.size()-1 != ' ']) prompt.push_back(' ');

    
    // Error checking for argv
    bool state = (argc == 4 && string(argv[1]) == "stateful") ? true : false;
    if (state){
      ss.clear();
      ss.str(argv[2]);
      if (!(ss >> max_clients)) throw((string) "Bad Max Clients Parameter");
      ss.clear();
      ss.str(argv[3]);
      if (!(ss >> min_rssi)) throw((string) "Bad Minimum RSSI");
    }
    // Set up router based on state 
    t = (state) ? router.Set_Up(state, max_clients, min_rssi) : router.Set_Up(state);
    if (t != "") throw(t);
    router.Print_State();
  } catch (string t) {    // handle instantiation errors
    cerr << "Usage: router_tester state(Stateful/Stateless) -- if stateless add options --> max_clients min_rssi [prompt] \n";
    if (t != "") cerr << t << endl;
    return 1;
  }
  // Handle user prompt
  while (1) {
    cout << prompt;
    cout.flush();

    if(!getline(cin, line)) return 0;

    sv.clear();
    ss.clear();
    ss.str(line);
    while (ss >> t) sv.push_back(t);
    // Handle operations
    if (sv.size() == 0 || sv[0][0] == '#') {
    } else if (sv[0] == "A") {                  // Add new client
      if (sv.size() < 4) {
        cout << "Usage: A name rssi mac\n";
      } else {
        name = sv[1];
        rssi = stoi(sv[2]);
        mac_address = sv[3];
        t = router.Add(name, rssi, mac_address);
        if (t != ""){
        cout << "A " << name << " " << rssi << " " << mac_address << endl;
          cout << t << endl;
        }
      }
    } else if (sv[0] == "F") {                 // Find client
      if (sv.size() != 2){
        cout << "Usage: F mac_address\n";
      } else {
        t = router.Find(sv[1]);
        if (t == ""){
          cout << "Not found. \n";
        } else {
          cout << "Found: \n" << t << endl;
        }
      }
    } else if (sv[0] == "P") {                // Print all clients
      router.printAll();                      // and router state  
    } else if (sv[0] == "Q") {                // Exit program
      return 0;
    } else if (sv[0] == "?") {                // Print Help
      print_commands();
    } else {
      printf("Unkown command %s\n", sv[0].c_str()); // Catchall
    }

  }

  
  
}
