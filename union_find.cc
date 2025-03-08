#include <cassert>

#include "union_find.h"

using namespace std;

UF::UF(
    int64_t total_nodes) :
  total_nodes_(total_nodes),
  root_(total_nodes),
  size_(total_nodes, 1),
  largest_node_(total_nodes),
  total_connections_(1) {

  for (int64_t i = 0; i < total_nodes; ++i) {
    root_[i] = i;
    largest_node_[i] = i;
  }
}

bool UF::IsValidNode(int64_t node) const {
  return node < total_nodes_;
}

bool UF::IsAllNodesConnected() const {
  return total_connections_ == total_nodes_;
}

int UF::MaxHeight() const {
  int max_height = -1;
  for (int64_t i = 0; i < total_nodes_; ++i) {
    int h = 1;
    int64_t parent = i;
    while (parent != root_[parent]) {
      ++h;
      parent = root_[parent];
    }
    max_height = std::max(max_height, h);
  }
  return max_height;
}

int64_t UF::FindRoot(int64_t node) const {
  if (!IsValidNode(node)) {
    return -1;
  }
  int64_t i = node;
  while (root_[i] != i) {
    const int64_t parent = root_[i];
    const int64_t gp = root_[parent]; // grand parent
    if (parent != gp) {
      // Path compression
      root_[i] = gp;
      // A subtree moved from parent to grandparent
      // Update the total nodes below parent.
      size_[parent] -= size_[i];
    }
    i = parent;
  }
  return i;
}

bool UF::IsConnected(int64_t p, int64_t q) {
  if (!IsValidNode(p) || !IsValidNode(q)) {
    return false;
  }
  return FindRoot(p) == FindRoot(q);
}

void UF::Union(int64_t p, int64_t q) {
  if (!IsValidNode(p) || !IsValidNode(q)) {
    return;
  }
  const int64_t pr = FindRoot(p);
  const int64_t qr = FindRoot(q);
  if (pr == qr) {
    // P and Q are already connected
    return;
  }

  // Establish a new connection
  const int64_t pr_sz = size_[pr];
  const int64_t qr_sz = size_[qr];
  const int64_t largest_node = std::max(largest_node_[pr], largest_node_[qr]);

  if (pr_sz <= qr_sz) {
    // P's root has less nodes. Move it under Q's root
    root_[pr] = qr;
    size_[qr] += pr_sz;
    largest_node_[qr] = largest_node;
  } else if (pr_sz > qr_sz) {
    // Move Q's Root under P's root
    root_[qr] = pr;
    size_[pr] += qr_sz;
    largest_node_[pr] = largest_node;
  }
  // account a new connection
  ++total_connections_;
  assert(total_connections_ <= total_nodes_);
}

int64_t UF::FindLargestNodeInComponent(int64_t node) const {
  int64_t root = FindRoot(node);
  if (root < 0) {
    return -1;
  }
  return largest_node_[root];
}
