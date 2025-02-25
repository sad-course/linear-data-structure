//
// Created by mirla-lopes on 12/11/24.
//
#include <ostream>

#include "node.h"
#ifndef LINKED_LIST_H
#define LINKED_LIST_H



class LinkedList {

protected:
    Node *head;

public:
    LinkedList();
    ~LinkedList();
    static Node *getNext(Node *node);
    Node *getHead();

    virtual void addNode(int firstElement, int secondValue);
    void addNode(Node *node);
    void deleteNode(Node *node);
    void changeNodeData(Node &node, int firstValue, int secondValue);
    int getLength();

    bool nodeExists(int firstValue, int secondValue);
    Node* search(int firstValue, int secondValue) const;
    void listNodes();

};

#endif //LINKED_LIST_H
