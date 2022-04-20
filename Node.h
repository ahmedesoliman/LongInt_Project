/**
 * @file Node.h
 * @author Ahmed Soliman ()
 * @brief
 * @version 0.1
 * @date 04-20-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef NODE_H
#define NODE_H

template <class T>
struct Node
{
    T data;
    Node *prev;
    Node *next;
};

#endif