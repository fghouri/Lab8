# Router Client Hash Table Project

## Overview

This project implements a simple router client table using a hash-table-style interface.  
The router stores connected clients using a client name, RSSI value, and MAC address.

The project supports two router modes:

- **Stateless mode**: accepts clients without enforcing capacity or RSSI limits.
- **Stateful mode**: accepts a maximum number of clients and a minimum RSSI threshold.

The main executable is:
```bash
bin/router_tester
```
## Project Structure
```
.
├── include/
│   ├── client.hpp
│   └── router.hpp
├── src/
│   ├── client.cpp
│   ├── router.cpp
│   └── router_tester.cpp
├── tests/
│   ├── test_stateful.sh
│   └── test_stateless.sh
├── Makefile
└── README.md
```

## Build
Pre-requisites
```
chmod 744 tests/test_stateless.sh
chmod 744 tests/test_stateful.sh
mkdir bin
mkdir obj
```
Compile everything using:
```
make
```
## **IF MAKE FAILS WITH MISSING SEPARATOR**
- Cause: transfer from windows to linux replaces tab/newline with spaces
- Solution: delete all indents up to previous line then hit enter and tab to make a new newline and tab indent
- Affected lines: 14 21 24 27 33
Transferring from linux to linux make runs just fine. 

This produces:
```
bin/router_tester
```
To clean compiled files:
```
make clean
```

# Running the Program
## Stateless Mode
```
./bin/router_tester stateless
```
- No limits on number of clients
- No RSSI filtering
## Stateful Mode
```
./bin/router_tester stateful <max_clients> <min_rssi>
```
Example:
```
./bin/router_tester stateful 40 -100
```
- Maximum of 40 clients
- Only accepts clients with RSSI ≥ -100

## Supported Commands
Add Client
```
A name rssi mac_address
```
- Adds client to router table.
Find Client
```
F mac_address
```
Print All Clients
```
P
```
- Prints entire client table
Quit
```
Q
```
- Exits the program
Help
```
?
```
- Displays available commands

## Test Scripts
Two test scripts are provided to automate testing

tests/test_stateless.sh
Tests the router in stateless mode.
Behavior:
- Adds 50 clients
- Performs 15 successful finds
- Performs 5 failed finds
- Prints table
- Exits
Run:
```bash
bash tests/test_stateless.sh
```

tests/test_stateful.sh
Tests the router in stateful mode.
Behavior:
- Attempts to add 50 clients
- Router limit: 40 clients
- RSSI threshold: -100
- Performs 20 finds
- Prints table
- Exits
Run:
```bash
bash tests/test_stateful.sh
```

## Example Inputs
```
A User_1 -60 aa:bb:cc:dd:ee:01
A User_2 -70 aa:bb:cc:dd:ee:02
F aa:bb:cc:dd:ee:01
F ff:ff:ff:ff:ff:ff
P
Q
```

# Contributors:
## Faraz Ghouri
## Casey Higgins










