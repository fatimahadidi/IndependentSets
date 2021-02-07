#ifndef NODESET_H
#define NODESET_H

#include "Node.h"
#include <vector>

class NodeSet
{
  public:
    NodeSet();
    void sort();
    void add(Node n);
    Node getLargestNode();
    bool isEmpty();
    int numNodes();

  protected:

  private:
    std::vector<Node> nodes;
};

#endif // NODESET_H
