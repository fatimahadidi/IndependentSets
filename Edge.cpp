#include "Edge.h"
#include <sstream>

/**
  Construct an Edge between the nodes with id's x and y.
  If x > y, Edge(x,y) will return Edge(y,x). Edge(x,x) is not allowed.

  @param x and y are integer node ids
  @returns Edge
*/
Edge::Edge(long x, long y)
{
  if (x == y) {
    throw std::invalid_argument("Self-referential edges are not allowed");
  } else if (x > y) {
    a = y;
    b = x;
  } else {
    a = x;
    b = y;
  }
}


/**
  Defines the == operator on Edges.
*/
bool Edge::operator==(const Edge &other) const
{
  return a == other.a && b == other.b;
}


/**
  Parses a string of two numbers separated by a space into an Edge

    "2 3" -> Edge(2, 3)
    "3 2" -> Edge(2,3)

  @param 'str' a string of two integers, space separated
  @returns an Edge between the two integers
*/
Edge Edge::parseEdgeStr(std::string str) {
  std::stringstream ss(str);
  std::string s;
  const char delim = ' ';

  std::getline(ss, s, delim);
  long a = stol(s);

  std::getline(ss, s, delim);
  long b = stol(s);

  return Edge(a,b);
}
