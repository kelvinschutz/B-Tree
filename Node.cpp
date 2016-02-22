/**
 @file Node.cpp
 @brief Implementation of base Node Class
 @author Brandon Theisen, Jason Pederson, Kelvin Shultz, Chris, Jared
*/
#include "Node.h"
#include <vector>
#include <iostream>
using namespace std;

//-----CONSTRUCTOR-----\\

/**Default Constructor for Node
 @post Creates a base Node for either a leaf node or a interior node*/
template<class T>
Node<T>::Node()
{
    capacity = 6; //6 is default
    //Default Constructor
}

//-----CONSTRUCTOR WITH CAPACITY-----\\

/**Default Constructor for Node with capacity
 @pre Accepts a capacity for a node, depending on what type of node is being created
 @param cap: capacity of the size in the node
 @post Creates a base Node for either a leaf node or a interior node with a capacity*/
template<class T>
Node<T>::Node(int cap)
{
    capacity = cap;
}

//-----COPY CONSTRUCTOR-----\\

/**Copy constructor that copies the node that calls it
 @pre Accepts a node to be copied
 @param Node to be copied
 @post Copies the node that called the constructor*/
template<class T>
Node<T>::Node(const Node& newCopy)
//: keys(newCopy.keys), capacity(newCopy.capacity), parentPtr(newCopy.parentPtr)
{}

//-----GET KEY AT-----\\

/**Returns the key at its position
 @pre Position must be less than keys.size()
 @param position: position of key that is being called
 @post Returns the position of the key being searched*/
template<class T>
int Node<T>::getKeyAt(int position)
{
    return keys.at(position);
}

//-----SEARCH KEYS-----\\

/**Search Keys
 @param key: key that will be searched for
 @post Return the position of the key in the vector of keys*/
template<class T>
int Node<T>::searchKey(int key)
{
    for(int i = 0; i < keys.size(); i++)
    {
        if(key < keys.at(i))
        {
            return i;
        }
    }
    return keys.size();
}

//-----ADD NEW KEY-----\\

/**Add a key
 @pre Node must have room for the new key. size() <= capacity
 @param newKey: key that will be entered
 @post Return true or false on if the key was successfully added*/
template<class T>
int Node<T>::addKey(int newKey)
{

    for(int i = 0; i < keys.size(); i++)
    {
        if(newKey < keys.at(i))
        {
            keys.insert(keys.begin() + i, newKey);
            return i;
        }
        else if(newKey == keys.at(i))
            return -1;
    }
    //We add the newKey to the end, since it was larger than all existing.
    //We checked to make sure there is room to add a key, otherwise
    //push_back would be overextending our keys <vector>.
    //With the precondition met, a push_back() is OK.
    int position = keys.size();
    keys.push_back(newKey);
    return position;
}


//-----GET PARENT-----\\

/**Get Parent of Node
 @post Return the parent of the node, otherwise will return NULL*/
template<class T>
Node<T>* Node<T>::getParent()
{
    return parentPtr;
}

//-----SET PARENT-----\\

/**Set Parent to a Node
 @param newParentPtr: pointer to be set as parent to a node
 @post Sets the parent to the node to newParentPtr*/
template<class T>
void Node<T>::setParent(Node<T>* newParentPtr)
{
    parentPtr = newParentPtr;
}

/**Get the size of the nodes child
 @post Return the size the child node*/
template<class T>
int Node<T>::getChildSize()
{
    return 0;
}

//-----GET SIZE-----\\

/**Get the size of the node
 @post Return the number of items in the node*/
template<class T>
int Node<T>::getSize()
{
    return keys.size();
}

//-----CONTAINS-----\\

/**Checks to see if a key is contained in the node
 @param key: key that will be searched for
 @post Return true or false depending if the key was found*/
template<class T>
bool Node<T>::contains(int key)
{
    for(int i = 0; i < keys.size(); i++)
    {
        if(key < keys.at(i))
        {   //Exit early because we are checking a sorted list
            //If the previous comparison was greater than, and now it is less than,
            //it clearly is not in the list and would be between these two comparisons.
            //As in, key > 5 but then key < 7 on the next loop, so it does not exist.
            return false;
        }
        else if(key == keys.at(i))
        {   //We found a match
            return true;
        }
    }
    //No matches were found
    return false;
}


//-----SPLIT-----\\

/**Split Node
 @param newNodePtr: pointer to node that will be split, provided by the B+ Tree class
 @post Creates a new node and places half the keys into the new node*/
template<class T>
void Node<T>::split(Node<T>* &newNodePtr)
{
    int value = getSize();
    for(int i = (keys.size()/2); i < keys.size(); i++)
    {
        newNodePtr->addKey(getKeyAt(i));
    }
    //Clear out the keys that were just moved from the existing node
    keys.erase(keys.begin() + (keys.size()/2), keys.end());
    //Check parent for an open pointer in children <vector>.
    //If none are available, a split will be required.
}


//-----MERGE-----\\

/**Merge two nodes together
 @param otherNodePtr: Pointer of the node the be merged with
 @post Merges the two nodes together, placing all keys into the orinigal node*/
template<class T>
void Node<T>::mergeNodes(Node<T>* &otherNodePtr)
{
    for(int i = 0; i < otherNodePtr->getSize(); i++)
    {
        //Since the keys will be in order and otherNode is to the right,
        //we can simply use push_back() to insert.
        keys.push_back(otherNodePtr->getKeyAt(i));
    }

    //otherNode.getParent() and set it to NULL, since we are deleting its child.
    //Check parent to see if we should be merging it with a sibling, after
    //deleting one of its children.

    delete otherNodePtr;
    otherNodePtr = NULL;
}


//-----DESTRUCTOR-----\\
//
template<class T>
Node<T>::~Node()
{
    //Destructor
}
