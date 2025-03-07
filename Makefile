all: union_find_main social_network_connectivity

union_find_main: union_find_main.cc union_find.cc
	g++ -std=c++14 union_find_main.cc union_find.cc -o union_find_main

social_network_connectivity: social_network_connectivity.cc union_find.cc
	g++ -std=c++14  social_network_connectivity.cc union_find.cc -o social_network_connectivity
