/** GNU AFFERO GENERAL PUBLIC LICENSE*/

#include <unordered_set>

#ifndef NODE_H
#define NODE_H

/** Class 'Node' records the number of and id's of a node's neighbors.
*/
class Node
{
  public:
    Node(int nodeID);
    std::unordered_set<int> *neighbors;

    int getSize();
    int getID();
    void addNeighbor(int nodeID);
    void removeNeighbor(int nodeID);

    bool operator < ( Node& other) ;

  protected:
    int id;
    int nodeSize = 0;
};

#endif // NODE_H
