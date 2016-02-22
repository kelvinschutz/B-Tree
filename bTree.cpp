/**
 @file bTree.cpp
 @brief Implementation of bTree class
 @author Brandon Theisen, Jason Pederson, Kelvin Schutz, Chris Scholl, Jared Kareniemi
*/

#include <iostream>
#include "Node.h"
#include "InteriorNode.h"
#include "LeafNode.h"
#include "bTree.h"
using namespace std;

/**Creates a bTree
 @pre Called onto a interior node
 @post Set the child to the node which is being called by*/
template <class T>
bTree<T>::bTree()
{
    rootPtr = new LeafNode<T>;
}

/**Prints a record found within the tree
 @pre N/A
 @param key: The key to the record that is to be printed
 @post Print all information about the record*/
template <class T>
void bTree<T>::printRecord(int key)
{
    //Search down the tree until we reach a Leaf Node
    Node<T>* tmpPtr = searchLeaf(rootPtr, key);
    //Check the Leaf Node if it contains the key before calling getKeyAt()
    if(tmpPtr->contains(key))
    {
        //Use searchKey to return the position to pass to getKeyAt() and print it
        cout << "Record found using key of " << key << ": "
            << tmpPtr->getKeyAt(searchKey(key)) << endl;
        return true;
    }
    return false;
}

/**Inserts a key/record pair into the B+ Tree
 @param key:    A key used to insert the value into the tree
 @param value:  The record to be stored into a Leaf Node
 @pre N/A
 @post Returns true or false depending if the key/value pair was successfully added*/
template <class T>
bool bTree<T>::insertRecord(key, value)
{
    //Check to see if we will be adding the first values to the first node of the tree
    if(rootPtr->getSize() == 0)
    {
        rootPtr->addValue(value, rootPtr->addKey(key));
        return true;
    }
    //Check to see if the key already exists
    else if(!treeContains(rootPtr, key))
    {
        //Search down the tree until we reach a Leaf Node
        Node<T>* tempPtr = searchLeaf(rootPtr, key);
        //Add the passed key and value into the previously returned Leaf Node
        //Inserts the value into the position that the key returns after adding itself
        tempPtr->addValue(value, tempPtr->addKey(key));
    }
    //We have found a value with the existing key
    return false;
}

/**Searches down the tree to see if a key exists within it.
 @param keyToFind: A key to find within the tree
 @post Returns true or false depending on whether the key was found or not*/
bool bTree<T>::treeContains(int keyToFind)
{
    //Calls the recursive searchLeaf function to find the Leaf Node to search
    tempPtr = searchLeaf(rootPtr, keyToFind);
    //Call the contains function of the Leaf Node to sequentially search through for the key
    //Contains will return true if it is found, and fall if it is not found
    return tempPtr->contains(keyToFind);
}

/**Searches down the tree to find the Leaf Node corresponding to a key
 @param keyToFind: A key to find within the tree
 @pre A treeContains() has been called before this function
 @post Returns the Leaf Node containing the key*/
Node<T>* bTree<T>::searchLeaf(Node<T>* aNodePtr, int keyToFind)
{
    //Temporarily store the child of the passed node corresponding to keyToFind
    Node<T>* tempPtr = aNodePtr->getChild(keyToFind);
    //Check to see if the passed node is a Leaf Node
    //Leaf Nodes return 0 when getChildSize is called because they have no children
    if(aNodePtr->getChildSize() == 0)
        return aNodePtr;
    //Otherwise, we are at an InteriorNode and will check its children with another call
    return searchLeaf(tempPtr, keyToFind);
}

/**Deletes a record from the tree
 @param key: the key corresponding to the record value
 @post Returns true or false depending if the record was successfully deleted*/
template <class T>
bool bTree<T>::deleteRecord(int key)
{
    //Calls the recursive searchLeaf function to find the Leaf Node to search
    Node<T>* tempPtr = searchLeaf(rootPtr, key);
    //Check the returned Leaf Node for the key with contains()
    if(tempPtr->contains(key))
    {
        //Remove the key and record from the Leaf Node
        return true;
    }
    //The key was not found
    return false;
}

/**Checks the tree to see if it is balanced
 @pre Called onto a interior node
 @param aTree: The tree to be checked
 @post Returns true or false depeneding if the tree is balanced or not*/
template <class T>
bool bTree<T>::checkTree(bTree aTree) {}

/**Rebuild the tree to be balance
 @pre Tree is currently unbalanced
 @param
 @post Change the tree to be balanced*/
template <class T>
void bTree<T>::rebuildTree(bTree &aTree) {}

template <class T>
bTree<T>::~bTree()
{
    //dtor
}
