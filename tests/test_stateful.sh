for i in {1..50}; do echo "A User_$i -60 aa:bb:cc:dd:ee:$i"; done > input.txt
# 20 Finds (all within the first 40)
for i in {1..20}; do echo "F aa:bb:cc:dd:ee:$i"; done >> input.txt
echo "P" >> input.txt
echo "Q" >> input.txt
./bin/router_tester stateful 40 -100 < input.txt
