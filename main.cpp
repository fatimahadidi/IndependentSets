/** GNU AFFERO GENERAL PUBLIC LICENSE*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#include "EdgeSet.h"
#include "NodeSet.h"


using std::string;


int main(int argc, char *argv[])
{

    std::ifstream file(argv[1]);
    string str;

    int numNodes;
    //int numEdges;

    getline(file, str);
    numNodes = stoi(str);


    Node *nodes[numNodes];

    //std::priority_queue<Node> orderedNodes = std::priority_queue<Node>();

    NodeSet orderedNodes = NodeSet();

    EdgeSet edges = EdgeSet();

    for (int i = 0; i < numNodes; i++) {
        Node *n = new Node(i);
        nodes[i] = n;
        orderedNodes.add(n);
    }


    //process lines for the edges to fill in nodes, orderedNodes and edges

    while (getline(file,str)) {

        Edge e = Edge::parseEdgeStr(str);

        int a = e.a;
        int b = e.b;


        nodes[a]->addNeighbor(b);

        nodes[b]->addNeighbor(a);

        //std::cout << "a.size = " << nodes[a]->nodeSize << ", b = " << nodes[b]->nodeSize << std::endl;

        edges.addEdge(e);
    }

    orderedNodes.sort();

    //std::cout << "num nodes: " << orderedNodes.numNodes() << std::endl;
    //std::cout << "num edges: " << edges.numEdges() << std::endl;

    //test greedy alg

    while (!edges.isEmpty()) {
        Node n = orderedNodes.getLargestNode();

        //std::cout << "largest node id: " << n.getID() << " with size " << n.nodeSize << std::endl;

        for (int neigh : *(n.neighbors)) {
            edges.remove(n.getID(), neigh);
            nodes[neigh]->removeNeighbor(n.getID());
        }

        orderedNodes.sort();

        //std::sort(orderedNodes.begin(), orderedNodes.end() );
    }

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
