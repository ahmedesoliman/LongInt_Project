/**
 * Programmer: Ahmed Soliman
 * Date: 2022-03-10
 * Purpose: Header file for UDLList class
 * UDLList is an unordered (unsorted) list.
 *
 */

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <string>
#include "Node.h"
#include "ListIterator.cpp"

template <class T>
class DoublyLinkedList
{
private:
    // length represents the number of items in the list
    int length;
    // first is a pointer to the first node in the list
    Node<T> *first;

    // last is a pointer to the last node in the list
    Node<T> *last;

    // destroyList deletes all existing list items and reinitializes
    // the doubly linked list with length = 0, first = last = NULL
    void destroyList();

    // findNode uses sequential search to find the node in the list
    // that contains the item. It then returns a pointer to that node.
    // If the item does not exist, findNode returns a null pointer.
    // I extracted this code into a private service function because it is used
    // by both deleteItem and searchItem.
    Node<T> *findNode(const T &) const;

    // copyList copies the items from another list into the current list.
    // If the current list already contains nodes, they are first deleted.
    void copyList(const DoublyLinkedList<T> &);

public:
    // Default constructor
    DoublyLinkedList();
    // Copy constructor
    DoublyLinkedList(const DoublyLinkedList &);
    // Destructor
    ~DoublyLinkedList();
    // Overloaded operatator=
    const DoublyLinkedList<T> &operator=(const DoublyLinkedList &);
    // getLength returns the length of the list
    int getLength() const;
    // isEmpty returns true if there are no nodes in the list
    bool isEmpty() const;
    // toString() returns a string representation of the list
    // This is useful for unit testing so we can see the list contents
    // without having to stub or mock std::cout
    std::string toString() const;
    // printList prints the contents of the list to std out
    void printList() const;
    // searchItem returns true if the item is in the list; false otherwise
    bool searchItem(const T &) const;
    // insertFirst adds an item to the front of the list
    void insertFirst(const T &);
    // insertLast adds an item to the back of the list
    void insertLast(const T &);
    // deleteFirst deletes the first item in the list
    void deleteFirst();
    // deleteLast deletes the last item in the list
    void deleteLast();
    // deleteItem deletes an item from the list, if it is present.
    // If the same item appears more than once in the list, only the first one is deleted.
    void deleteItem(const T &);
    // iteratorBegin returns an iterator at the first item
    const ListIterator<T> iteratorBegin() const;
    // iteratorEnd retursn an interator at the last item
    const ListIterator<T> iteratorEnd() const;
};

#endif