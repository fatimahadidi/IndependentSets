/** GNU AFFERO GENERAL PUBLIC LICENSE*/
#ifndef NODESET_H
#define NODESET_H

#include "Node.h"
#include <vector>


/**
    NodeSet provides the functionality of a priority queue for Nodes
*/
class NodeSet
{
  public:
    NodeSet();
    bool isEmpty();
    long numNodes();

    void sortAscending();
    void sortDescending();
    void add(Node *n);
    Node getLastNode();

  private:
    long numTies;
    long currentMax;
    long currentMaxNode;
    std::vector<Node*> nodes;
};

/** Custom comparator for comparing nodes by the number of neighbors.
    Here, Node a is less than Node b if it has fewer neighbors than Node b*/

struct NodeComparatorFewestNeighs {
    bool operator () (Node* a, Node* b) {
        return a->getSize() < b->getSize();
    }

};

/** Custom comparator for comparing nodes by the number of neighbors.
    Here, Node a is less than Node b if it has more neighbors than Node b*/
struct NodeComparatorMostNeighs {
    bool operator () (Node* a, Node* b) {
        return a->getSize() > b->getSize();
    }

};

#endif // NODESET_H
