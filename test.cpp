
#include <vector>
#include <iostream>
#include "Node.h"
#include "InteriorNode.h"
#include "LeafNode.h"

using namespace std;

void printNode(Node<int>* aNodePtr);
void printTree(Node<int>* rootPtr);
void printLeaf(Node<int>* aNodePtr);
bool treeContains(Node<int>* rootPtr, int keyToFind);
Node<int>* searchLeaf(Node<int>* rootPtr, int keyToFind);
void addKeyValuePair(Node<int>* nodePtr, int key, int value);

Node<int>* rootPtr;
Node<int>* tempPtr;
int blockSize = 2;

int main()
{
/*
    int input = 1;
    int key = 1;

    cout << "Create Parent 1:" << endl;
    tempPtr = new InteriorNode<int>;
    addKeyValuePair(tempPtr, key+2, input+2);
    printLeaf(tempPtr);
    rootPtr = tempPtr;

    //cout << "Create Leaf 1:" << endl;
    tempPtr = new LeafNode<int>;
    addKeyValuePair(tempPtr, key, input);
    addKeyValuePair(tempPtr, key+1, input+1);
    addKeyValuePair(tempPtr, key+2, input+2);
    addKeyValuePair(tempPtr, key+1, input+5);
    //printLeaf(tempPtr);

    cout << "Child Node Added: " << endl;
    rootPtr->setChild(tempPtr, 0);
    printLeaf(rootPtr->getChild(2));

    //cout << "Create Leaf 2:" << endl;
    tempPtr = new LeafNode<int>;
    addKeyValuePair(tempPtr, key+3, input+3);
    addKeyValuePair(tempPtr, key+4, input+4);
    addKeyValuePair(tempPtr, key+5, input+5);
    addKeyValuePair(tempPtr, key+3, input+6);
    //printLeaf(tempPtr);

    cout << "Child Node Added: " << endl;
    rootPtr->setChild(tempPtr, 1);
    printLeaf(rootPtr->getChild(4));

    addKeyValuePair(rootPtr, 7, 7);
    cout << "LeafNode: " << endl;
    printNode(tempPtr);
    cout << "RootNode: " << endl;
    printNode(rootPtr);

    addKeyValuePair(rootPtr, 0, 10);
    cout << "LeafNode: " << endl;
    printNode(tempPtr);
    cout << "RootNode: " << endl;
    printNode(rootPtr);


    cout << "Create Leaf: " << endl;
    tempPtr = new LeafNode<int>;
    addKeyValuePair(tempPtr, 1, 1);
    addKeyValuePair(tempPtr, 2, 2);
    printLeaf(tempPtr);
    cout << endl;

    cout << "Create Leaf: " << endl;
    tempPtr = new LeafNode<int>;
    addKeyValuePair(tempPtr, 3, 3);
    addKeyValuePair(tempPtr, 4, 4);
    printLeaf(tempPtr);
    cout << endl;

    cout << "Create Leaf: " << endl;
    tempPtr = new LeafNode<int>;
    addKeyValuePair(tempPtr, 5, 5);
    addKeyValuePair(tempPtr, 6, 6);
    printLeaf(tempPtr);
    cout << endl;

    cout << "Create Leaf: " << endl;
    tempPtr = new LeafNode<int>;
    addKeyValuePair(tempPtr, 7, 7);
    addKeyValuePair(tempPtr, 8, 8);
    printLeaf(tempPtr);
    cout << endl;

*/
    //-----TEST LEAF NODE-----\\
    //
    int value = 5;
    Node<int>* Int1Ptr = new InteriorNode<int>;
    Node<int>* Int2Ptr = new InteriorNode<int>(*Int1Ptr);
    Node<int>* L1Ptr = new LeafNode<int>;
    Node<int>* L2Ptr = new LeafNode<int>(*L1Ptr);

    for(int i = 1; i < 7; i++)
    {
        L1Ptr->addKey(i);
    }

    for(int i = 1; i < 7; i++)
    {
        Int1Ptr->addKey(i);
    }


    cout << "L1Ptr: " << endl;
    printNode(L1Ptr);
    cout << "L2Ptr: " << endl;
    printNode(L2Ptr);
    cout << endl;

    L1Ptr->split(L2Ptr);

    cout << "L1Ptr: " << endl;
    printNode(L1Ptr);
    cout << "L2Ptr: " << endl;
    printNode(L2Ptr);
    cout << endl;

    L1Ptr->mergeNodes(L2Ptr);

    cout << "L1Ptr: " << endl;
    printNode(L1Ptr);
    //The node that L2Ptr points to will be deleted
    //Attempting to print it will result in a crash

    //Test Contains
    //cout << L1Ptr->contains(0) << endl;
    //cout << "L1Ptr Size: " << L1Ptr->getSize() << endl;

    cout << "Int1Ptr Size: " << Int1Ptr->getSize() << endl;
    cout << "Int1Ptr Size: " << endl;
    printNode(Int1Ptr);

    cout << "Child Pointer Location: " << Int1Ptr->searchKey(3) << endl;


    Node<int>* Child1Ptr = new LeafNode<int>(*L1Ptr);
    Node<int>* Child2Ptr = new LeafNode<int>(*L1Ptr);
    Node<int>* Child3Ptr = new LeafNode<int>(*L1Ptr);
    Node<int>* Child4Ptr = new LeafNode<int>(*L1Ptr);
    Node<int>* L3Ptr = new LeafNode<int>(*L1Ptr);

    InteriorNode<int>* Int3Ptr = new InteriorNode<int>;
    InteriorNode<int>* Int4Ptr = new InteriorNode<int>(5);
    Int3Ptr->addKey(3);
    Int3Ptr->addKey(6);
    Int3Ptr->addKey(9);

    for(int i = 1; i < 4; i++)
    {
        Child1Ptr->addKey(i);
        Child2Ptr->addKey(i+3);
        Child3Ptr->addKey(i+6);
        Child4Ptr->addKey(i+9);
        Child1Ptr->addValue(i, i-1);
        Child2Ptr->addValue(i+3, i-1);
        Child3Ptr->addValue(i+6, i-1);
        Child4Ptr->addValue(i+9, i-1);
        L3Ptr->addKey(i+3);
        cout << "Add Value: " << i+3 << " at " << i-1 << endl;
        L3Ptr->addValue(i*12, i-1);
    }


    cout << "Before Insert Child: " << Int3Ptr->getChildSize() << endl;
    Int3Ptr->setChild(Child1Ptr, 0);
    cout << "Insert Child: " << Int3Ptr->getChildSize() << endl;
    Int3Ptr->setChild(Child2Ptr, 1);
    cout << "Insert Child: " << Int3Ptr->getChildSize() << endl;
    Int3Ptr->setChild(Child3Ptr, 2);
    cout << "Insert Child: " << Int3Ptr->getChildSize() << endl;
    Int3Ptr->setChild(Child4Ptr, 3);
    cout << "Insert Child: " << Int3Ptr->getChildSize() << endl;
    Int3Ptr->removeChild(1);
    Int3Ptr->removeKey(1);
    cout << "Remove Child: " << Int3Ptr->getChildSize() << endl;
    Int3Ptr->addKey(L3Ptr->getKeyAt(L3Ptr->getSize()-1));
    Int3Ptr->setChild(L3Ptr, 1);
    cout << "Insert Leaf: " << Int3Ptr->getChildSize() << endl;


    printNode(Int3Ptr);
    printNode(Int3Ptr->getChild(3));
    printNode(Int3Ptr->getChild(4));
    printNode(Int3Ptr->getChild(8));
    printNode(Int3Ptr->getChild(20));
    //Int3Ptr->getChild(0)->addKey(5);

    if(Int3Ptr->getChild(20) == nullptr)
        cout << "YUP, IT'S NULL!" << endl;
    cout << endl << endl;

    //int testKey = 12;
    //cout << "Position of key in child: " << searchLeaf(Int3Ptr,testKey)->searchKey(testKey) << endl;

    //cout << "Leaf Node: " << endl;
    //printLeaf(L3Ptr);


    int testKey = 5;
    if(treeContains(Int3Ptr, testKey))
    {
        cout << "TRUE" << endl;
        cout << "The key corresponds to a value of ";
        cout << searchLeaf(Int3Ptr, testKey)->findValue(testKey) << endl;
    }
    else
        cout << "FALSE" << endl;
    cout << endl;

    cout << tempPtr->getKeyAt(0) << endl;
/*
    //-----TEST INTERIOR NODE-----\\
    //
    Node<int>* Int1Ptr = new InteriorNode<int>;
    Node<int>* Int2Ptr = new InteriorNode<int>(*Int1Ptr);

    for(int i = 1; i < 6; i++)
    {
        Int1Ptr->addKey(i);
    }

    cout << "Int1Ptr: " << endl;
    printNode(Int1Ptr);
    cout << "Int2Ptr: " << endl;
    printNode(Int2Ptr);
    cout << endl;

    Int1Ptr->split(Int2Ptr);

    cout << "Int1Ptr: " << endl;
    printNode(Int1Ptr);
    cout << "Int2Ptr: " << endl;
    printNode(Int2Ptr);
    cout << endl;

    Int1Ptr->mergeNodes(Int2Ptr);

    cout << "Int1Ptr: " << endl;
    printNode(Int1Ptr);
    //The node that L2Ptr points to will be deleted
    //Attempting to print it will result in a crash
*/

    return 0;
}

void addKeyValuePair(Node<int>* nodePtr, int key, int value)
{
    if(nodePtr->getSize() == 0)
    {
        nodePtr->addValue(value, nodePtr->addKey(key));
    }
    else if(!treeContains(nodePtr, key))
    {
        Node<int>* tmpPtr = searchLeaf(rootPtr, key);
        tmpPtr->addValue(value, tmpPtr->addKey(key));
    }
}

void printNode(Node<int>* aNodePtr)
{
    for(int i = 0; i < aNodePtr->getSize(); i++)
    {
        cout << aNodePtr->getKeyAt(i) << " ";
    }
    cout << endl;
}

void printLeaf(Node<int>* aNodePtr)
{
    printNode(aNodePtr);
    for(int i = 0; i < aNodePtr->getSize(); i++)
    {
        cout << aNodePtr->findValue(aNodePtr->getKeyAt(i)) << " ";
    }
    cout << endl;
}

void printTree(Node<int>* rootPtr)
{
    for(int i = 0; i < rootPtr->getSize(); i++)
    {
        printNode(rootPtr->getChild((i+1)*3));
    }
}

bool treeContains(Node<int>* rootPtr, int keyToFind)
{
    tempPtr = searchLeaf(rootPtr, keyToFind);
    return tempPtr->contains(keyToFind);
}

Node<int>* searchLeaf(Node<int>* rootPtr, int keyToFind)
{
    Node<int>* tempPtr = rootPtr->getChild(keyToFind);
    printLeaf(tempPtr);
    if(tempPtr->getChildSize() == 0)
        return tempPtr;
    return searchLeaf(tempPtr, keyToFind);
}
