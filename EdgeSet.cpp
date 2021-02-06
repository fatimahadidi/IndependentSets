#include "EdgeSet.h"

EdgeSet::EdgeSet()
{
  edges = std::unordered_set<Edge, EdgeHash>();
}

void EdgeSet::add(int x, int y) {
  edges.insert(Edge(x,y));
}

void EdgeSet::remove(int x, int y) {
  edges.erase(Edge(x,y));
}

bool EdgeSet::isEmpty() {
  return edges.empty();
}
