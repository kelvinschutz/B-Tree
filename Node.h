/**
 @file Node.h
 @brief Base Node Class
 @author Brandon Theisen, Jason Pederson, Kelvin Shultz, Chris, Jared
*/
#ifndef _NODE
#define _NODE
#include <vector>
using namespace std;

template<class T>
class Node
{
protected:
    vector<int> keys;       //Container for the keys within the node
    Node<T>* parentPtr;     //Points to the parent node
    int capacity;           //Block size for all nodes (Passed through constructor)

//----- TO DO -----\\
//Remove virtual from functions and remove generic functions from Leaf and Interior Nodes
//If the function is not defined in Leaf Node, it will simply call Node implementation.
//As long as the implementation is not different between Leaf and Interior Nodes, do it that way.
//Split and Merge are different because of the need to split/merge children, values, *next, *prev, etc.
//A-Level will need to be defined and have operators overloaded.
public:
    Node();

    Node(int cap);

    //Copy Constructor
    Node(const Node& newCopy);

    //GET KET AT
    int getKeyAt(int position);

    //SEARCH KEY
    virtual int searchKey(int key);

    //ADD KEY
    virtual int addKey(int newKey) = 0;

    //GET PARENT
    Node<T>* getParent();

    //SET PARENT
    void setParent(Node<T>* newParentPtr);

    //GET SIZE
    int getSize();

    //GET CHILD SIZE
    virtual int getChildSize();

    //GET CHILD
    virtual Node<T>* getChild(int key) = 0;

    //SET CHILD
    //virtual void setChild(Node<T>* newChild, int position) = 0;

    //CONTAINS
    bool contains(int key);

    //SPLIT
    virtual void split(Node<T>* &newNodePtr) = 0;

    //MERGE
    virtual void mergeNodes(Node<T>* &otherNodePtr) = 0;

    //Destructor
    virtual ~Node();
};

#include "Node.cpp"
#endif // _NODE
