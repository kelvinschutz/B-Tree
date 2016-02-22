/**
 @file LeafNode.cpp
 @brief Implementation of LeafNode class
 @author Brandon Theisen, Jason Pederson, Kelvin Shultz, Chris, Jared
*/
#include "LeafNode.h"
#include <vector>
#include <iostream>
using namespace std;

//-----CONSTRUCTOR-----\\

/**Default Constructor for LeafNode
 @post Creates a leaf node*/
template<class T>
LeafNode<T>::LeafNode()
{
    //Node<T>::Node();
    //capacity = 6; //6 is default
    //Default Constructor
}

//-----CONSTRUCTOR WITH CAPACITY-----\\

/**Default Constructor for LeafNode
 @param cap: Capicity of the node
 @post Creates a leaf node with a set capicity*/
template<class T>
LeafNode<T>::LeafNode(int cap)
{
    Node<T>::Node(cap);
}

//-----COPY CONSTRUCTOR AS NODE-----\\

/**Copy constructor that copies the node that calls it
 @pre Accepts a node to be copied
 @param Node to be copied
 @post Copies the node that called the constructor*/
template<class T>
LeafNode<T>::LeafNode(const Node<T>& newCopy)
{}

//-----ADD NEW KEY-----\\

/**Add a key
 @pre Node must have room for the new key. size() <= capacity
 @param newKey: key that will be entered
 @post Return true or false on if the key was successfully added into the vector of keys*/
template<class T>
int LeafNode<T>::addKey(int newKey)
{
    //return true;
    return Node<T>::addKey(newKey);
}

//-----GET CHILD-----\\

/**Returns the child where the key located
 @param key: key to be searched for
 @post Returns the node where the key is located*/
template<class T>
Node<T>* LeafNode<T>::getChild(int key)
{
    return this;
}

/**Sets the child of a node
 @pre Called onto a interior node
 @param newChild: The child to be set
 @param position: Position of the node
 @post Set the child to the node which is being called by*/
template<class T>
void LeafNode<T>::setChild(Node<T>* newChild, int position)
{
    cout << "Don't call me!" << endl;
}

//-----SPLIT-----\\

/**Split node
 @param newNodePtr: Pointer to the new node that is being created
 @post Splits the node by placing half of the key into a new node*/
template<class T>
void LeafNode<T>::split(Node<T>* &newNodePtr)
{
    Node<T>::split(newNodePtr);
}

//-----MERGE-----\\

/**Merge two nodes together
 @param otherNodePtr: Pointer of the node the be merged with
 @post Merges the two nodes together, placing all keys into the orinigal node*/
template<class T>
void LeafNode<T>::mergeNodes(Node<T>* &otherNodePtr)
{
    Node<T>::mergeNodes(otherNodePtr);
}


//-----DESTRUCTOR-----\\
//
template<class T>
LeafNode<T>::~LeafNode()
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
