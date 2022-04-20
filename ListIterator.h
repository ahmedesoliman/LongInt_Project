/**
 * @file ListIterator.h
 * @author Ahmed Soliman ()
 * @brief Header file for ListIterator class
 * ListIterator allows a client to iterate through a DoublyLinkedList.
 *
 * NOTES:
 * A ListIterator is meant to point to the nodes of an external linked list.
 * It is not meant to hold its own copy of that list.
 *
 * For these reasons, clients should keep the following in mind:
 * 1. If the underlying linked list that the iterator points to is destroyed,
 * reassigned to a new list, or goes out of scope while the ListIterator remains
 * in scope, this will cause errors and other problems.
 * 2. Deleting a node in the list may also cause problems
 * if the iterator happens to be pointing to the deleted node at that time.
 * 3. Therefore, clients should not delete the underlying list or list nodes while the current iterator exists
 * 4. It is better to ensure that the iterator is deleted (or goes out of scope) before
 * doing any destructive operations on the list.
 * 5. Because the ListIterator is not meant to keep "its own copy" of the underlying list,
 * I have not implemented copy constructor, operator= overloads, or special destructor logic.
 * The default behavior of those methods is what is desired here.
 * @version 0.1
 * @date 04-20-2022
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

#include "Node.h"

template <class T>
class ListIterator
{
private:
    // curr is a pointer to a node in a DoublyLinkedList
    Node<T> *curr;

public:
    // Default constructor
    ListIterator();
    // Constructor with a node; should not copy the underlying list
    ListIterator(Node<T> *);
    // Copy constructor
    ListIterator(const ListIterator<T> &);
    // Destructor should not delete the underlying list
    ~ListIterator();
    // hasNext() returns true if curr is not null, false if null
    bool hasNext() const;
    // hasPrect() returns true if curr is not null, fals if null
    bool hasPrev() const;
    // The next method returns the current data, then moves curr to the next element
    // Clients should ALWAYS check that hasNext() returns true before calling next()
    T next();
    // The prev() method returns the current data, then moves curr to the previous element
    // Clients should ALWAYS check that hasPrev() returns true BEFORE calling prev()
    T prev();

    // Overload of dereferencing operator
    // This will print the data of the current node without advancing curr
    T operator*();

    // Reassign the value of the data at the current node
    void operator=(const T &);
};
#endif