/**
 @file InteriorNode.h
 @brief InteriorNode class
 @author Brandon Theisen, Jason Pederson, Kelvin Shultz, Chris, Jared
*/
#ifndef _INTERIOR_NODE
#define _INTERIOR_NODE
#include <vector>
#include "Node.h"
using namespace std;

template<class T>
class InteriorNode : public Node<T>
{
private:
    //vector<int> keys;
    vector<Node<T>* > children;

public:
    InteriorNode();

    InteriorNode(int cap);

    //Copy Constructor
    InteriorNode(const Node<T>& newCopy);

    //GET CHILD SIZE
    int getChildSize();

    //GET CHILD
    Node<T>* getChild(int key);

    //SET CHILD
    void setChild(Node<T>* newChild, int position);

    //REMOVE CHILD
    void removeChild(int position);

    //SEARCH KEY
    int searchKey(int key);

    //ADD KEY
    int addKey(int newKey);

    //REMOVE KEY
    void removeKey(int position);

    //SPLIT
    void split(Node<T>* &newNodePtr);

    //MERGE
    void mergeNodes(Node<T>* &otherNodePtr);

    //DESTRUCTOR
    virtual ~InteriorNode();

    //These functions are implemented in Node.h
    int getSize();
    Node<T>* getParent();
    void setParent(Node<T>* newParentPtr);
    int getKeyAt(int position);
    bool contains(int key);

};

#include "InteriorNode.cpp"
#endif // _INTERIOR_NODE
