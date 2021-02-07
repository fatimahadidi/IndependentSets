#include "Node.h"

Node::Node(int nodeID)
{
  id = nodeID;
  nodeSize = 0;

  neighbors = new std::unordered_set<int>();

}

bool Node::operator<(const Node &other) const{
  return nodeSize < other.nodeSize;
}

void Node::addNeighbor(int nodeID) {
  neighbors->insert(nodeID);
  nodeSize++;
}

void Node::removeNeighbor(int nodeID) {
  neighbors->erase(nodeID);
  nodeSize = std::max(0, nodeSize - 1);
}

int Node::getID() {
  return id;
}


