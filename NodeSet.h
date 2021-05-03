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

    void sort();
    void add(Node *n);
    Node getLargestNode();

  private:
    std::vector<Node*> nodes;
};

/** Custom comparator for comparing nodes by size*/
struct NodeComparator {
    bool operator () (Node* a, Node* b) {
        return a->getSize() < b->getSize();
    }

};

#endif // NODESET_H
