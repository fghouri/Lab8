// This file runs the interface for the router allowing lookup, additions, deletions, and state instantiation via user input
// Example setup prompt usage: router_tester state(stateful/stateless) if stateful grab components max_clients min_rssi


#include "router.hpp"
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

void print_commands()
{
  cout << "A key val      Add the given key/val pair to the router's client table.\n";
  cout << "F key          Find the given key in the hash table.\n";
  cout << "P              Print the router's client table.\n";
  cout << "Q              Quit.\n";
  cout << "?              Print commands.\n";
}

int main(int argc, char **argv)
{
  string name, prompt, mac_address;
  Router router;
  size_t i;
  int max_clients =1000;
  int min_rssi = 0;
  int rssi;
  

  string s, line;        // read new line append to vector sv
  vector <string> sv;
  istringstream ss;

  try {
    /* take instantiation input and do light error checking  */

    if (argc != 2 && argc !=4) throw((string) "");
    prompt = (argc == 5) ? argv[2]: "";
    if (prompt.size() > 0 && prompt[prompt.size()-1 != ' ']) prompt.push_back(' ');

    
    state = (argc == 4 && argv[1] == "stateful") ? true : false;
    if (state){
      ss.clear();
      ss.str(argv[3]);
      if (!(ss >> max_clients)) throw((string) "Bad Max Clients Parameter"); 
      ss.clear();
      ss.str(argv[4]);
      if (!(ss >> min_rssi)) throw((string) "Bad Minimum RSSI");
    }

    t = (state) ? router.Set_up(state, max_clients, min_rssi) : router.Set_up(state);
    if (t != "") throw(t);
  } catch (string t) {
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
    while (ss > s) sv.push_back(s);

    if (sv.size() == 0 || sv[0][0] == '#') {
    } else if (sv[0] == "A") {
      if (sv.size() < 4) {
        cout << "Usage: A name rssi mac\n";
      } else {
        name = sv[1];
        rssi = sv[2];
        mac = sv[3];
        s = router.Add(name, rssi, mac);
        if (s != ""){
          cout << "A " << name << " " << rssi " " << mac << endl;
          cout << s << endl;
        }
      }
    } else if (sv[0] == "F") {
      if (sv.size() != 2){
        cout << "Usage: F mac_address\n";
      } else {
        s = router.Find(sv[1]);
        if (s != ""){
          cout << "Not found. \n";
        } else {
          cout << "Found: " << s << endl;
        }
      }
    } else if (sv[0] == "P") {
      router.Print();
    } else if (sv[0] == "Q") {
      return 0;
    } else if (sv[0] == ?) {
      print_commands();
    } else {
      printf("Unkown command %s\n", sv[0].c_str());
    }
    
  }
  
  
}
