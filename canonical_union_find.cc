#if 0
Union-find with specific canonical element. Add a method find() to the
union-find data type so that find(i) returns the largest element in the
connected component containing i. The operations, union(), connected(), and
find() should all take logarithmic time or better. For example, if one of the
connected components is {1,2,6,9}, then the find() method should return 9 for
each of the four elements in the connected components.
#endif

#include <cassert>

#include "union_find.h"

int main() {
  UF uf(16);
  uf.Union(1, 2);
  uf.Union(2, 6);
  uf.Union(9, 6);
  int64_t largest = uf.FindLargestNodeInComponent(1);
  assert(largest == 9);

  largest = uf.FindLargestNodeInComponent(2);
  assert(largest == 9);

  return 0;
}
