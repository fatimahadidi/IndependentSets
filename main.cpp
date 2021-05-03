/** GNU AFFERO GENERAL PUBLIC LICENSE*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#include "MostNeighborsRemoved.cpp"


using std::string;


int main(int argc, char *argv[])
{

    std::ifstream file(argv[1]);
    string str;

    long numNodes;

    getline(file, str);
    numNodes = stol(str);

    Node *nodes[numNodes];
    NodeSet orderedNodes = NodeSet();
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


    mostNeighborsRemoved(nodes, &orderedNodes, &edges, numNodes);


    if (orderedNodes.isEmpty()) {
        std::cout << "No independent set found\n";
    } else {
        std::cout << "independent set of size " << orderedNodes.numNodes() << " found:"<< std::endl;

        while (!orderedNodes.isEmpty()) {
            Node n = orderedNodes.getLargestNode();
            std::cout << n.getID() << std::endl;
        }
    }


    return 0;
}
