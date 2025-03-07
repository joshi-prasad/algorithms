#include <iostream>
#include <string>

#include "union_find.h"

using namespace std;

void Test1() {
  int total_nodes = 8192;
  UF uf(total_nodes);
  for (const int inc : {293, 223, 181, 109, 97, 59, 53, 41, 2, 3, 5, 11, 13, 17, 19, 23, 29, 31, 37, 41, 2, 1}) {
    for (int i = 0; i < total_nodes; i+=inc) {
      uf.Union(i, i+7);
    }
  }
  for (int i = 0; i < total_nodes; ++i) {
    cout << "IsConnected " << i << " " << i+1 << " " << uf.IsAllNodesConnected() << std::endl;
    uf.Union(i, i+1);
    if (uf.IsAllNodesConnected()) {
      std::cout << "All connected: " << i << std::endl;
      break;
    }
  }
}

void Test2() {
  int64_t total_nodes;
	std::cout << "Total Nodes: ";
	std::cin >> total_nodes;
	UF uf(total_nodes);

	string command;
	int64_t num1, num2;

	cout << "Enter inputs (format: <command> <num1> <num2>), press Ctrl+D to stop:\n";

	// Read inputs until EOF (Ctrl+D)
	while (cin >> command >> num1 >> num2) {
		// Validate command
    if (num1 >= total_nodes || num2 >= total_nodes) {
      cout << "The node numbers must be less than " << total_nodes << std::endl;
      continue;
    }
		if (command == "connect") {
      uf.Union(num1, num2);
    } else if (command == "is_connected") {
      std::cout << (uf.IsConnected(num1, num2) ? "yes" : "no") << "\n";
		} else {
			cerr << "Invalid command! Please use 'connect' or 'is_connected'.\n";
		}
	}

	cout << "End of input detected.\n";
}

int main() {
  Test1();
  Test2();
  return 0;
}
