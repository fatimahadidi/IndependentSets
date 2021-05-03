/** GNU AFFERO GENERAL PUBLIC LICENSE*/

#include <unordered_set>

#ifndef NODE_H
#define NODE_H

/** Class 'Node' records the number of and id's of a node's neighbors.
*/
class Node
{
  public:
    Node(long nodeID);
    std::unordered_set<long> *neighbors;

    long getSize();
    long getID();
    void addNeighbor(long nodeID);
    void removeNeighbor(long nodeID);

    bool operator < ( Node& other) ;

  protected:
    long id;
    long nodeSize = 0;
};

#endif // NODE_H
