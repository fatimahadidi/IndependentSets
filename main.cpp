/** GNU AFFERO GENERAL PUBLIC LICENSE*/
#include <iostream>
#include <fstream>
#include <string>
#include <queue>


#include "NodeQueue.h"
#include "MostNeighborsRemoved.cpp"
#include "FewestNeighborsSelected.cpp"


using std::string;


int main(int argc, char *argv[])
{

    std::ifstream file(argv[1]);
    string str;

    long numNodes;

    getline(file, str);
    numNodes = stol(str);

    Node *nodes[numNodes];
    NodeQueue orderedNodes = NodeQueue();
    EdgeSet edges = EdgeSet();

    for (long i = 0; i < numNodes; i++) {
        Node *n = new Node(i);
        nodes[i] = n;
        orderedNodes.add(n);
    }

    //process the remaining lines to fill in nodes and edges
    while (getline(file,str)) {
        Edge e = Edge::parseEdgeStr(str);

        long a = e.a;
        long b = e.b;

        nodes[a]->addNeighbor(b);
        nodes[b]->addNeighbor(a);

        edges.addEdge(e);
    }


    NodeQueue* solution = mostNeighborsRemoved(nodes, &orderedNodes, &edges, numNodes);


    if (solution->isEmpty()) {
        std::cout << "No independent set found\n";
    } else {
        std::cout << "independent set of size " << solution->numNodes() << " found:"<< std::endl;

        while (!solution->isEmpty()) {
            Node n = solution->getLastNode();
            std::cout << n.getID() << std::endl;
        }
    }


    return 0;
}
