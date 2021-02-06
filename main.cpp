#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

#include "Node.h"
#include "EdgeSet.h"
#include "utils.h"


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

    std::priority_queue<Node> orderedNodes = std::priority_queue<Node>();

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
        orderedNodes.push(*n);
    }

    //test greedy alg

    while (!edges.isEmpty()) {
        Node n = orderedNodes.top();

        for (int neigh : *n.neighbors) {
            edges.remove(n.getID(), neigh);
            nodes[neigh]->removeNeighbor(n.getID());
        }
        orderedNodes.pop();
    }

    if (orderedNodes.empty()) {
        std::cout << "No independent set found\n";
    } else {

        while (!orderedNodes.empty()) {
            Node n = orderedNodes.top();
            std::cout << n.getID() << std::endl;
            orderedNodes.pop();
        }

    }









    return 0;
}
