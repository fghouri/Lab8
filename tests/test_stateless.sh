# 50 Additions
for i in {1..50}; do echo "A User_$i -60 00:11:22:33:44:$i"; done > input.txt
# 20 Finds (15 existing, 5 fake)
for i in {1..15}; do echo "F 00:11:22:33:44:$i"; done >> input.txt
for i in {1..5}; do echo "F ff:ff:ff:ff:ff:$i"; done >> input.txt
echo "P" >> input.txt
echo "Q" >> input.txt
./router_tester stateless < input.txt
