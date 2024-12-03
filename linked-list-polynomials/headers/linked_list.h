//
// Created by mirla-lopes on 12/11/24.
//
#include "node.h"
#ifndef LINKED_LIST_H
#define LINKED_LIST_H



class LinkedList {
    private:
        Node *head;

    public:
        LinkedList();
        ~LinkedList();
        void addNode(Node *node);
        void addNode(int firstElement, int secondValue);
        void deleteNode(Node *node);

        Node *getNext(Node *node);
        void changeNodeData(Node &node, int firstValue, int secondValue);
        int getLength();
        bool nodeExists(Node *node);
        void listAllElements();

        int getPolynomialDegree();
};
#endif //LINKED_LIST_H
