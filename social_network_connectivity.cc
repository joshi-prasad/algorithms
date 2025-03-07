#if 0
Descripton:
Social network connectivity. Given a social network containing n members and a
log file containing m timestamps at which times pairs of members
formed friendships, design an algorithm to determine the earliest time
at which all members are connected (i.e., every member is a friend of
a friend of a friend ... of a friend). Assume that the log file is
sorted by timestamp and that friendship is an equivalence relation.
The running time of your algorithm should be O(m x log(n)) or better
and use extra space proportional to n.
#endif

#include <vector>
#include <string>
#include <tuple>
#include <iostream>

#include "union_find.h"

using namespace std;

int main() {
  int n = 5;
  vector<tuple<string, int, int>> log = {
    {"2023-03-01 10:00", 0, 1},
    {"2023-03-01 10:05", 1, 2},
    {"2023-03-01 10:10", 3, 4},
    {"2023-03-01 10:15", 2, 3}, // This step connects all members
    {"2023-03-01 10:16", 0, 4},
    {"2023-03-01 10:17", 2, 4},
  };

  UF uf(n);
  for (const auto& e : log) {
    uf.Union(std::get<1>(e), std::get<2>(e));
    if (uf.IsAllNodesConnected()) {
      std::cout << "Timestamp: " << std::get<0>(e) << std::endl;
      break;
    }
  }
  return 0;
}
