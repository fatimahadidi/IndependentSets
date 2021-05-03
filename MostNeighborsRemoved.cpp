
#include "EdgeSet.h"
#include "NodeSet.h"


static void mostNeighborsRemoved(Node** nodes, NodeSet *orderedNodes, EdgeSet *edges, long n){

  while (!edges->isEmpty()) {

    orderedNodes->sort();

    Node n = orderedNodes->getLargestNode();

    for (int neigh : *(n.neighbors)) {
        edges->remove(n.getID(), neigh);
        nodes[neigh]->removeNeighbor(n.getID());
    }
  }

}
