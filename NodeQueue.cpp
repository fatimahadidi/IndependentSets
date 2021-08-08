/** GNU AFFERO GENERAL PUBLIC LICENSE*/

#include "NodeQueue.h"
#include <algorithm>

/**
  Constructs an empty NodeQueue
*/
NodeQueue::NodeQueue()
{
  nodes = std::vector<Node*>();
}


/** Returns whether set is empty*/
bool NodeQueue::isEmpty() {
  return nodes.empty();
}


/** Returns the number of Nodes in this set */
long NodeQueue::numNodes() {
  return nodes.size();
}


/**
  Adds Node n to the set
  @param n is a Node pointer
*/
void NodeQueue::add(Node *n) {
  nodes.push_back(n);
}

/**
  Removes Node pointer n
  @param n is a Node pointer
  O(size of queue)
*/
void NodeQueue::remove(Node *n) {
  int i = 0;
  while (nodes[i] != n && i < nodes.size()) {
    i++;
  }
  if (i < nodes.size()) {
    nodes.erase(nodes.begin()+i);
  }
}

/**
  Returns the node (or one of the nodes in case of a tie) with the most neighbors in the set

  @returns largest Node (most neighbors) in the set
*/
Node NodeQueue::getLastNode() {
  Node *n = nodes.back();
  nodes.pop_back();
  return *n;
}


/**
  Sorts the Nodes currently in the set, fewest neighbors first
*/
void NodeQueue::sortAscending() {
  std::sort(nodes.begin(), nodes.end(), NodeComparatorFewestNeighs());
}



/**
  Sorts the Nodes currently in the set, most neighbors first
*/
void NodeQueue::sortDescending() {
  std::sort(nodes.begin(), nodes.end(), NodeComparatorMostNeighs());
}

