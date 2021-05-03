/** GNU AFFERO GENERAL PUBLIC LICENSE*/
#include "EdgeSet.h"


/**
  Constructs an empty EdgeSet
*/
EdgeSet::EdgeSet()
{
  edges = std::unordered_set<Edge, EdgeHash>();
}


/** Returns whether set is empty*/
bool EdgeSet::isEmpty() {
  return edges.empty();
}


/** Returns the number of edges in the set*/
long EdgeSet::numEdges() {
  return edges.size();
}


/**
  Adds an edge between nodes with id's x and y to the set
  @param x, y are integer node ids
*/
void EdgeSet::add(long x, long y) {
  edges.insert(Edge(x,y));
}


/**
  Removes the edge between node ids x and y from this set
  @param x, y are integer node ids
*/
void EdgeSet::remove(long x, long y) {
  edges.erase(Edge(x,y));
}


/**
  Adds the given edge to this set
  @param e is an Edge
*/
void EdgeSet::addEdge(Edge e) {
  edges.insert(e);
}


/**
  Removes the given edge from this set
  @param e is an Edge
*/
void EdgeSet::removeEdge(Edge e) {
  edges.erase(e);
}

