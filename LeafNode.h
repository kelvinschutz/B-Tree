/**
 @file LeafNode.h
 @brief LeafNode class
 @author Brandon Theisen, Jason Pederson, Kelvin Shultz, Chris, Jared
*/
#ifndef _LEAF_NODE
#define _LEAF_NODE

#include <vector>
#include "Node.h"
using namespace std;

template<class T>
class LeafNode : public Node<T>
{
public:
    LeafNode();

    LeafNode(int cap);

    //Copy Constructor
    LeafNode(const Node<T>& newCopy);

    //ADD KEY
    int addKey(int newKey);

    //GET CHILD
    Node<T>* getChild(int key);

    //SET CHILD
    void setChild(Node<T>* newChild, int position);

    //SPLIT
    void split(Node<T>* &newNodePtr);

    //MERGE
    void mergeNodes(Node<T>* &otherNodePtr);

    virtual ~LeafNode();

    //These functions are implemented in Node.h
    int getSize();
    Node<T>* getParent();
    void setParent(Node<T>* newParentPtr);
    int getKeyAt(int position);
    bool contains(int key);
};

#include "LeafNode.cpp"
#endif // _Leaf_NODE
