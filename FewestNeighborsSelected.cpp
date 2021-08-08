/** GNU AFFERO GENERAL PUBLIC LICENSE*/
#include "EdgeSet.h"
#include "NodeQueue.h"


static NodeQueue* fewestNeighborsSelected(Node** nodes, NodeQueue* orderedNodes, EdgeSet *edges, long n){

  NodeQueue* solution = new NodeQueue();


  while (!orderedNodes->isEmpty()) {

    orderedNodes->sortDescending();

    Node n = orderedNodes->getLastNode();
    solution->add(&n);

    for (int neigh : *(n.neighbors)) {
      orderedNodes->remove(nodes[neigh]);
    }
    orderedNodes->remove(&n);

  }
    return solution;
}

