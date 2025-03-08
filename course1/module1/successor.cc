#if 0
Successor with delete. Given a set of n integers S={0,1,...,n−1} and a
sequence of requests of the following form:

1. Remove x from S
2. Find the successor of x: the smallest y in S such that y >= x.

Design a data type so that all operations (except construction)  take
logarithmic time or better in the worst case.
#endif

#include <cassert>
#include <vector>
#include <iostream>

#include "union_find.h"

using namespace std;

int64_t Successor(UF* s, int64_t node) {
  if (s->IsAllNodesConnected()) {
    return -1;
  }
  return s->FindLargestNodeInComponent(node);
}

void Remove(UF* s, int64_t node) {
  int64_t nodes_root = Successor(s, node);
  int64_t next_root = Successor(s, node+1);
  s->Union(nodes_root, next_root);
}

int main() {
  const int64_t kTotalNodes = 1024;

  // Assume S has 1024 integers from 0 to 1023
  UF s(kTotalNodes);

  // Test: Successor of each node is itself
  for (int64_t i = 0; i < kTotalNodes; ++i) {
    assert(Successor(&s, i) == i);
  }

  // Test: Remove a node 3
  Remove(&s, 3);

  // Test: Successor of a node 2 is 2
  int64_t r = Successor(&s, 2);
  assert(r == 2);

  // Test: Since 3 is removed it's successor is 4
  r = Successor(&s, 3);
  assert(r == 4);

  for (int64_t i = 4; i < kTotalNodes; ++i) {
    assert(Successor(&s, i) == i);
  }

  // Test: Remove a node 4
  Remove(&s, 4);
  Remove(&s, 4);
  r = Successor(&s, 3);
  assert(r == 5);
  r = Successor(&s, 4);
  assert(r == 5);

  // Test: Remove node 6
  Remove(&s, 6);
  r = Successor(&s, 3);
  assert(r == 5);
  r = Successor(&s, 5);
  assert(r == 5);
  r = Successor(&s, 6);
  assert(r == 7);

  // Test: Remove node 5
  Remove(&s, 5);
  r = Successor(&s, 3);
  assert(r == 7);

  return 0;
}
