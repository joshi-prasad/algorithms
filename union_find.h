#ifndef __union_find__h__
#define __union_find__h__

#include <vector>

class UF {
public:
  UF(int64_t total_nodes);
  void Union(int64_t p, int64_t q);
  bool IsConnected(int64_t p, int64_t q);
  int MaxHeight() const;
  bool IsAllNodesConnected() const;
private:
  int64_t FindRoot(int64_t node);
  bool IsValidNode(int64_t node) const;
private:
  int64_t total_nodes_;
  std::vector<int64_t> root_;
  std::vector<int64_t> size_;
  int64_t total_connections_;
};


#endif
