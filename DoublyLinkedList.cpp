/**
 * @file DoublyLinkedList.cpp
 * @author Ahmed Soliman ()
 * @brief Implementation file for UDLList class
 * @version 0.1
 * @date 04-20-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "DLList.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    length = 0;
    first = last = NULL;
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T> &other)
{
    // set first to NULL so that copyList() doesn't try to destroy list
    first = NULL;
    copyList(other);
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    destroyList();
}

template <class T>
const DoublyLinkedList<T> &DoublyLinkedList<T>::operator=(const DoublyLinkedList<T> &other)
{
    if (this != &other)
        copyList(other);

    return *this;
}

template <class T>
void DoublyLinkedList<T>::copyList(const DoublyLinkedList<T> &other)
{
    // Destroy existing list, if any
    if (first != NULL)
        destroyList();

    // Handle empty source list
    if (other.isEmpty())
    {
        first = last = NULL;
        length = 0;
    }
    else
    {
        // Pointer p walks the list we want to copy FROM
        Node<T> *p = other.first;

        // Create new node
        first = new Node<T>;
        first->data = p->data;
        first->prev = first->next = NULL;

        // We will advance the last pointer as we create the list
        last = first;
        p = p->next;

        while (p != NULL)
        {
            // Create new node
            Node<T> *newNode = new Node<T>;
            newNode->data = p->data;
            newNode->next = NULL;

            // Add new node to end of list
            newNode->prev = last;
            last->next = newNode;

            // Advance pointers
            last = last->next;
            p = p->next;
        }

        length = other.length;
    }
}

template <class T>
void DoublyLinkedList<T>::destroyList()
{
    Node<T> *temp;

    while (first != NULL)
    {
        temp = first;
        first = first->next;
        // Set pointers to null for security
        temp->prev = NULL;
        temp->next = NULL;
        delete temp;
    }

    last = NULL;
    length = 0;
}

template <class T>
int DoublyLinkedList<T>::getLength() const
{
    return length;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty() const
{
    return first == NULL;
}

// Begin string conversion code derived from here: https://stackoverflow.com/a/39761578
template <class T>
string DoublyLinkedList<T>::toString() const
{
    // Create output stream to push all of our data into
    ostringstream out;
    Node<T> *curr = first;
    while (curr != NULL)
    {
        out << curr->data;
        if (curr->next != NULL)
            out << ", ";

        curr = curr->next;
    }
    // Convert the output stream to a std::string
    return out.str();
}
// End derived code

template <class T>
void DoublyLinkedList<T>::printList() const
{
    if (isEmpty())
        cout << "The list is empty." << endl;
    else
        cout << toString() << endl;
}

template <class T>
bool DoublyLinkedList<T>::searchItem(const T &item) const
{
    Node<T> *found = findNode(item);
    return found != NULL;
}

template <class T>
void DoublyLinkedList<T>::insertFirst(const T &item)
{
    // Create new node to insert
    Node<T> *newNode = new Node<T>;
    newNode->data = item;
    newNode->prev = NULL;

    // Place new node before first
    newNode->next = first;

    // Handle case where list is empty
    if (isEmpty())
        last = newNode;
    else
        first->prev = newNode;

    // Reassign first pointer and increment length
    first = newNode;
    length++;
}

template <class T>
void DoublyLinkedList<T>::insertLast(const T &item)
{
    // Create new node to insert
    Node<T> *newNode = new Node<T>;
    newNode->data = item;
    newNode->next = NULL;

    // Place new node after last
    newNode->prev = last;

    // Handle case where list is empty
    if (isEmpty())
        first = newNode;
    else
        last->next = newNode;

    // Reassign last pointer and increment length
    last = newNode;
    length++;
}

template <class T>
void DoublyLinkedList<T>::deleteFirst()
{
    if (isEmpty())
        cout << "Error: cannot delete from empty list" << endl;
    else
    {
        Node<T> *temp = first;

        // Advance first to next node
        first = first->next;

        // Handle case where list has only one item (will be empty after deletion)
        if (first == NULL)
            last = NULL;
        else
            first->prev = NULL;

        // Null out old first's next pointer for safety
        temp->next = NULL;

        // Delete old first and decrement length
        delete temp;
        length--;
    }
}

template <class T>
void DoublyLinkedList<T>::deleteLast()
{
    if (isEmpty())
        cout << "Error: cannot delete from empty list" << endl;
    else
    {
        Node<T> *temp = last;

        // Move last pointer back to previous
        last = last->prev;

        // Handle list that has only one item
        if (last == NULL)
            first = NULL;
        else
            last->next = NULL;

        // null out old last's (temp's) pointers for safety
        temp->prev = NULL;

        // Delete old last (temp) and decrement length
        delete temp;
        length--;
    }
}

template <class T>
void DoublyLinkedList<T>::deleteItem(const T &item)
{
    if (isEmpty())
        cout << "Error: cannot delete from empty list" << endl;
    else if (item == first->data)
        deleteFirst();
    else if (item == last->data)
        deleteLast();
    else
    {
        // Search for the item in the list
        Node<T> *nodeToDelete = findNode(item);

        // If a node containing the item exists, delete it
        if (nodeToDelete != NULL)
        {
            Node<T> *prevNode = nodeToDelete->prev;
            Node<T> *nextNode = nodeToDelete->next;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;

            // for safety, null out pointers of node we're deleting
            nodeToDelete->prev = nodeToDelete->next = NULL;

            delete nodeToDelete;
            length--;
        }
        else
            cout << item << " not found in list." << endl;
    }
}

template <class T>
Node<T> *DoublyLinkedList<T>::findNode(const T &item) const
{
    Node<T> *found = NULL;
    Node<T> *curr = first;

    while (curr != NULL && found == NULL)
    {
        if (curr->data == item)
            found = curr;
        else
            curr = curr->next;
    }

    return found;
}

template <class T>
const ListIterator<T> DoublyLinkedList<T>::iteratorBegin() const
{
    ListIterator<T> iterator(first);

    return iterator;
}

template <class T>
const ListIterator<T> DoublyLinkedList<T>::iteratorEnd() const
{
    ListIterator<T> iterator(last);

    return iterator;
}
