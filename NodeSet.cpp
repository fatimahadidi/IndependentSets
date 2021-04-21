/** GNU AFFERO GENERAL PUBLIC LICENSE*/

#include "NodeSet.h"
#include <algorithm>

/**
  Constructs an empty NodeSet
*/
NodeSet::NodeSet()
{
  nodes = std::vector<Node*>();
}


/** Returns whether set is empty*/
bool NodeSet::isEmpty() {
  return nodes.empty();
}


/** Returns the number of Nodes in this set */
int NodeSet::numNodes() {
  return nodes.size();
}


/**
  Adds Node n to the set
  @param n is a Node pointer
*/
void NodeSet::add(Node *n) {
  nodes.push_back(n);
}


/**
  Returns the node (or one of the nodes in case of a tie) with the most neighbors in the set

  @returns largest Node (most neighbors) in the set
*/
Node NodeSet::getLargestNode() {
  Node *n = nodes.back();
  nodes.pop_back();
  return *n;
}


/**
  Sorts the Nodes currently in the set, largest first
*/
void NodeSet::sort() {
  std::sort(nodes.begin(), nodes.end(), NodeComparator());
}




