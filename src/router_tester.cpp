// This file runs the interface for the router allowing lookup, additions, deletions, and state instantiation via user input
// Example setup prompt usage: router_tester table_size prompt(stateful) if stateful grab components max_clients min_rssi


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
  string key, prompt;
  Router client_table;
  size_t table_size;
  Client new_client;
  size_t i;

  string s, line;        // read new line append to vector sv
  vector <string> sv;
  istringstream ss;

  try {
    /* take instantiation input and do light error checking  */

    if (argc != 3 && argc !=2) throw((string) "");
    ss.clear();
    ss.str(argv[1]);
    if (!(ss >> table_size)) throw((string) "Bad Client Table Size");
    prompt = (argc == 3) ? argv[2]: "";
    if (prompt.size() > 0 && prompt[promt.size()-1 != ' ']) prompt.push_back(' ');

    t = client_table.Set_up(table_size);
    if (t != "") throw(t);
  } catch (string t) {
    cerr << "Usage: router_tester table-size state(Stateful/Stateless) -- if stateless add options --> max_clients min_rssi [prompt] \n";
    if (t != "") cerr << t << endl;
    return 1;
  }
  // Handle user prompt
  while (1) {
    
  }
  
  
}
