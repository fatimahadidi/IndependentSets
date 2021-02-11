#ifndef NODESET_H
#define NODESET_H

#include "Node.h"
#include <vector>

class NodeSet
{
  public:
    NodeSet();
    void sort();
    void add(Node *n);
    Node getLargestNode();
    bool isEmpty();
    int numNodes();

  protected:

  private:
    std::vector<Node*> nodes;
};

struct NodeComparator {
    bool operator () (const Node* a, const Node* b) {
        return a->nodeSize < b->nodeSize;
    }

};

#endif // NODESET_H
