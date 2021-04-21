/** GNU AFFERO GENERAL PUBLIC LICENSE*/
#include "Node.h"


/**
  Constructs a new Node with id 'nodeID'
  @param nodeID: int
  @returns Node(nodeID)
*/
Node::Node(int nodeID)
{
  id = nodeID;
  neighbors = new std::unordered_set<int>();
}


/**
  Defines < operator on Nodes
  @param 'other' is a Node
  @returns whether this node or 'other' has more neighbors
*/
bool Node::operator<( Node &other) {
  return nodeSize < other.getSize();
}


/**
  Adds a neighboring node's id to this node's neighbors.
  @param nodeID is the id of the node to add
*/
void Node::addNeighbor(int nodeID) {
  neighbors->insert(nodeID);
  nodeSize++;
}


/**
  Remove a neighboring node's id from this node's neighbors.
  @param nodeID is the id of the node to remove
*/
void Node::removeNeighbor(int nodeID) {
  neighbors->erase(nodeID);
  nodeSize = std::max(0, nodeSize - 1);
}

/** Getter for Node id */
int Node::getID() {
  return id;
}

/** Getter for Node size*/
int Node::getSize() {
  return nodeSize;
}
