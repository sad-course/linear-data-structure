//
// Created by mirla-lopes on 12/11/24.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class Node {

    private:
        int firstValue;
        int secondValue;
        Node *next = nullptr;

      public:
        Node(int firstValue, int secondValue);
        void destruct();
        int getFirstValue();
        int getSecondValue();
        void setFirstValue(int firstValue);
        void setSecondValue(int secondValue);

        Node *getNext();
        void setNext(Node &next);
};

class LinkedList {
    private:
        Node *head;

    public:
        LinkedList();
        void addNode(Node &node);
        void deleteNode(Node &node);
        Node getNext(Node &node);
        void changeNodeData(Node &node, int firstValue, int secondValue);
        bool nodeExists(Node &node);
        int getLength();

        void destruct();
        void listElements();
};
#endif //LINKED_LIST_H
