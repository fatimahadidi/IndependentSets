/** GNU AFFERO GENERAL PUBLIC LICENSE*/
#ifndef NodeQueue_H
#define NodeQueue_H

#include "Node.h"
#include <vector>


/**
    NodeQueue provides the functionality of a priority queue for Nodes
*/
class NodeQueue
{
  public:
    NodeQueue();
    bool isEmpty();
    long numNodes();

    void sortAscending();
    void sortDescending();
    void add(Node* n);
    void remove(Node* n);
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

#endif // NodeQueue_H
