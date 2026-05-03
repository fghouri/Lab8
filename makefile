CFLAGS ?= -std=c++98 -Wall -Wextra -Iinclude

# -------------------------
# This means that when you just type "make", you make all of the executables

ALL = bin/read_as_hex bin/hash_tester

all: $(ALL)

# -------------------------
# "make clean" deletes the object files and binaries

clean:
    rm -f obj/* bin/*

# -------------------------
# Object files

obj/client.o: src/client.cpp include/client.hpp
    g++ $(CFLAGS) -c -o obj/router.o src/router.cpp

obj/router.o: src/router.cpp include/router.hpp
    g++ $(CFLAGS) -c -o obj/router.o src/router.cpp

obj/router_tester.o: src/router_tester.cpp include/router.hpp
    g++ $(CFLAGS) -c -o obj/router_tester.o src/router_tester.cpp

# -------------------------
# Executables

bin/router_tester: obj/router_tester.o obj/router.o obj/
    g++ $(CFLAGS) -o bin/router_tester obj/router_tester.o obj/router.o


~
