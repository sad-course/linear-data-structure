//
// Created by mirla-lopes on 06/02/25.
//

#ifndef NODE_H
#define NODE_H
template <typename T>
struct Node{
    T data;
    Node<T>* next;
};

template <typename T>
struct DNode{
    T data;
    DNode *prev;
    DNode *next;
};


#endif //NODE_H
