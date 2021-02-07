#include "NodeSet.h"
#include <algorithm>

NodeSet::NodeSet()
{
  nodes = std::vector<Node>();
}

void NodeSet::add(Node n) {
  nodes.push_back(n);
}

Node NodeSet::getLargestNode() {
  Node n = nodes.back();
  nodes.pop_back();
  return n;
}

void NodeSet::sort() {
  std::sort(nodes.begin(), nodes.end());
}

bool NodeSet::isEmpty() {
  return nodes.empty();
}

int NodeSet::numNodes() {
  return nodes.size();
}


