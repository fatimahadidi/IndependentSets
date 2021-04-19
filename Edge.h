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
*/
class Edge
{
  public:
    Edge(int x, int y);

    int a;
    int b;

    bool operator == (const Edge &other) const;
    static Edge parseEdgeStr(std::string str);

};

class EdgeHash {
public:
  std::size_t operator() (const Edge &e) const {
    return (std::hash<int>()(e.a)) ^ (std::hash<int>()(e.b));
  }

};

#endif // EDGE_H
