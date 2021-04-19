#include "Edge.h"
#include <sstream>

/**
  construct
*/
Edge::Edge(int x, int y)
{
  if (x == y) {
    throw std::invalid_argument("Self-referential edges are note allowed");
  } else if (x > y) {
    a = y;
    b = x;
  } else {
    a = x;
    b = y;
  }
  //ctor
}

bool Edge::operator==(const Edge &other) const {
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
  int a = stoi(s);

  std::getline(ss, s, delim);
  int b = stoi(s);

  return Edge(a,b);

}
