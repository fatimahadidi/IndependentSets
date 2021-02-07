#include <unordered_set>

#ifndef EDGESET_H
#define EDGESET_H

#include "Edge.h"


class EdgeSet
{
  public:
    EdgeSet();
    void add(int x, int y);
    void remove(int x, int y);
    bool isEmpty();
    int numEdges();

  private:
    std::unordered_set<Edge, EdgeHash> edges;
};

#endif // EDGESET_H
