/** GNU AFFERO GENERAL PUBLIC LICENSE */

#include <cstddef>
#include <functional>
#include <string>

#ifndef EDGE_H
#define EDGE_H


/**
  Class 'Edge' defines an undirected edge between two nodes by recording
  the integer id of the two nodes, the smaller node id is always recorded first.

  Edge(a,b).equals(Edge(b,a)) holds.
  If a < b, Edge(a,b) returns Edge(b,a).
  Edge(a,a) is not allowed.
*/
class Edge
{
  public:
    Edge(long x, long y);

    long a;
    long b;

    bool operator == (const Edge &other) const;
    static Edge parseEdgeStr(std::string str);

};


/**
  Custom Hash for Edges
*/
class EdgeHash {
public:
  std::size_t operator() (const Edge &e) const {
    return (std::hash<long>()(e.a)) ^ (std::hash<long>()(e.b));
  }

};

#endif // EDGE_H
