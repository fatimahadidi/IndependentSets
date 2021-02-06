#include "Edge.h"

Edge::Edge(int x, int y)
{
  if (x > y) {
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
