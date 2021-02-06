#include <cstddef>
#include <functional>

#ifndef EDGE_H
#define EDGE_H

class Edge
{
  public:
    Edge(int x, int y);

    int a;
    int b;

    bool operator == (const Edge &other) const;

};

class EdgeHash {
public:
  std::size_t operator() (const Edge &e) const {
    return (std::hash<int>()(e.a)) ^ (std::hash<int>()(e.b));
  }

};

#endif // EDGE_H
