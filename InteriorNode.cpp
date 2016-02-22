/**
 @file InteriorNode.cpp
 @brief Implementation of InteriorNode class
 @author Brandon Theisen, Jason Pederson, Kelvin Shultz, Chris, Jared
*/
#include "InteriorNode.h"
#include <vector>
#include <iostream>
using namespace std;

//-----CONSTRUCTOR-----\\

/**Default Constructor for InteriorNode
 @post Creates a interiorNode*/
template<class T>
InteriorNode<T>::InteriorNode()
{
    Node<T>::capacity = 6;

    //Node<T>::Node();
    //capacity = 6; //6 is default
    //Default Constructor
}

//-----CONSTRUCTOR WITH CAPACITY-----\\

/**Default Constructor for Node with capacity
 @pre Accepts a capacity for a node, depending on what type of node is being created
 @param cap: capacity of the size in the node
 @post Creates a base Node for either a leaf node or a interior node with a capacity*/
template<class T>
InteriorNode<T>::InteriorNode(int cap)
{
    Node<T>::capacity = cap;
}

//-----COPY CONSTRUCTOR-----\\

/**Copy constructor that copies the node that calls it
 @pre Accepts a node to be copied
 @param Node to be copied
 @post Copies the node that called the constructor*/
template<class T>
InteriorNode<T>::InteriorNode(const Node<T>& newCopy)
{}

//-----GET CHILD SIZE-----\\

/**Get size of the node
 @post Returns the size of the node*/
template<class T>
int InteriorNode<T>::getChildSize()
{
    return children.size();
}

//-----GET CHILD-----\\

/**Returns the child where the key located
 @param key: key to be searched for
 @post Returns the node where the key is located*/
template<class T>
Node<T>* InteriorNode<T>::getChild(int key)
{
    return children.at(searchKey(key));
}


//-----SET CHILD-----\\

/**Sets the child of a node
 @pre Called onto a interior node
 @param newChild: The child to be set
 @param position: Position of the node
 @post Set the child to the node which is being called by*/
template<class T>
void InteriorNode<T>::setChild(Node<T>* newChild, int position)
{
    children.insert(children.begin() + position, newChild);
}

//-----REMOVE CHILD-----\\
//All removes of children must be accompanied by a removal of a key
template<class T>
void InteriorNode<T>::removeChild(int position)
{
    children.erase(children.begin() + position);
}


//-----SEARCH KEY-----\\

/**Searches for a key in a node
 @pre Called from a interior node
 @param key: The key to be searched for
 @post Returns the position of the key*/
template<class T>
int InteriorNode<T>::searchKey(int key)
{
    for(int i = 0; i < Node<T>::keys.size(); i++)
    {
        if(key <= Node<T>::keys.at(i))
        {
            return i;
        }
    }
    return Node<T>::keys.size();
}

//-----ADD NEW KEY-----\\

/**Add a key
 @pre Node must have room for the new key. size() <= capacity
 @param newKey: key that will be entered
 @post Return true or false on if the key was successfully added*/
template<class T>
int InteriorNode<T>::addKey(int newKey)
{
    //return true;
    return Node<T>::addKey(newKey);
}

//-----REMOVE KEY-----\\

/**Remove a key
 @pre Key must be located in the node
 @param position: Location of the key in the vector
 @post Removes the key from the vector*/
template<class T>
void InteriorNode<T>::removeKey(int position)
{
    Node<T>::keys.erase(Node<T>::keys.begin() + position);
}

//-----SPLIT-----\\

/**Split node
 @param newNodePtr: Pointer to the new node that is being created
 @post Splits the node by placing half of the key into a new node*/
template<class T>
void InteriorNode<T>::split(Node<T>* &newNodePtr)
{
    Node<T>::split(newNodePtr);
}


//-----MERGE-----\\

/**Merge two nodes together
 @param otherNodePtr: Pointer of the node the be merged with
 @post Merges the two nodes together, placing all keys into the original node*/
template<class T>
void InteriorNode<T>::mergeNodes(Node<T>* &otherNodePtr)
{
    Node<T>::mergeNodes(otherNodePtr);
}


//-----DESTRUCTOR-----\\
//
template<class T>
InteriorNode<T>::~InteriorNode()
{
    //Destructor
}

/*--These functions are implemented in Node.cpp
//
int getSize();
Node<T>* getParent();
void setParent(Node<T>* newParentPtr);
int getKeyAt(int position);
bool contains(int key);
*/
