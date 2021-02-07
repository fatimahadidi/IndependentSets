#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#include "EdgeSet.h"
#include "utils.h"
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


    //for the next numNodes lines, fill in nodes, orderedNodes and edges

    for (int i = 0; i < numNodes; i++) {

        getline(file, str);

        std::vector<int> neighboringNodes = parseInts(str);

        Node *n = new Node(i);

        for (int neigh: neighboringNodes) {
            n->addNeighbor(neigh);
            edges.add(i, neigh);
        }
        nodes[i] = n;

        orderedNodes.add(*n);

        //orderedNodes.push(*n);
    }

    orderedNodes.sort();

    //std::cout << "num nodes: " << orderedNodes.numNodes() << std::endl;
    //std::cout << "num edges: " << edges.numEdges() << std::endl;

    //test greedy alg

    while (!edges.isEmpty()) {
        Node n = orderedNodes.getLargestNode();

        //std::cout << "largest node id: " << n.getID() << std::endl;

        for (int neigh : *n.neighbors) {
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
