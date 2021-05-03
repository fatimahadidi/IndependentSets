/** GNU AFFERO GENERAL PUBLIC LICENSE*/
#include <unordered_set>

#ifndef EDGESET_H
#define EDGESET_H

#include "Edge.h"

/**
  EdgeSet provides the functionality for a set of Edges
*/
class EdgeSet
{
  public:
    EdgeSet();
    bool isEmpty();
    long numEdges();
    void add(long x, long y);
    void remove(long x, long y);
    void addEdge(Edge e);
    void removeEdge(Edge e);


  private:
    std::unordered_set<Edge, EdgeHash> edges;
};

#endif // EDGESET_H
