/** GNU AFFERO GENERAL PUBLIC LICENSE*/
#include "EdgeSet.h"
#include "NodeQueue.h"


static NodeQueue* mostNeighborsRemoved(Node** nodes, NodeQueue* orderedNodes, EdgeSet *edges, long n){

  while (!edges->isEmpty()) {

    orderedNodes->sortAscending();

    Node n = orderedNodes->getLastNode();

    for (int neigh : *(n.neighbors)) {
        edges->remove(n.getID(), neigh);
        nodes[neigh]->removeNeighbor(n.getID());
    }
  }

  return orderedNodes;
}
