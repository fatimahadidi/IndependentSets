#include <unordered_set>

#ifndef NODE_H
#define NODE_H


class Node
{
  public:
    Node(int nodeID);
    int nodeSize;
    std::unordered_set<int> *neighbors;

    void addNeighbor(int nodeID);
    void removeNeighbor(int nodeID);
    int getID();

    bool operator < (const Node& other) const;


  protected:
    int id;
};

#endif // NODE_H
