//
// Created by mirla-lopes on 13/11/24.
//

#include "linked_list.h"
#include "node.h"
#include <iostream>

LinkedList::LinkedList() {
    Node* head = new Node(0, 0);
    this->head = head;
}


/*
    Destruct the linked list
    while the head is not null, store in temporary node
    delete the head and get the next node
*/
LinkedList::~LinkedList() {
    while(head) {
        const Node* temp = head;
        head = head->getNext();
        delete temp;
    }
}

Node *LinkedList::getNext(Node *node) {
    return node->getNext();
}


//Tamanho de polinomio - T/t
int LinkedList::getLength() {
    Node *currentElement = this->head->getNext();
    int length = 0;
    while (currentElement != nullptr) {
        length++;
        currentElement = currentElement->getNext();
    }
    return length;
}


void LinkedList::addNode(Node *node) {
    Node* currentNode = this->head;

    while (currentNode->getNext() != nullptr) {
        currentNode = currentNode->getNext();
    }
    currentNode->setNext(node);
}


void LinkedList::addNode(int firstValue, int secondValue) {
    Node* currentNode = this->head;
    Node* createdNode = new Node(firstValue, secondValue);

    while (currentNode->getNext() != nullptr) {
        currentNode = currentNode->getNext();
    }
    currentNode->setNext(createdNode);

}

bool LinkedList::nodeExists(int firstValue, int secondValue) {
    Node* currentNode = this->head;
    Node createdNode = Node(firstValue, secondValue);

    while (currentNode != nullptr) {
        if (*currentNode == createdNode) {
            return true;
        }
        currentNode = currentNode->getNext();
    }
    return false;
}

void LinkedList::deleteNode(Node *node) {
    Node *currentNode = this->head;
    while (currentNode != nullptr) {
        Node *nextNode = this->getNext(currentNode);
        if (nextNode == node) {
            currentNode->setNext(this->getNext(nextNode));

            delete nextNode;

            return;
        }
        currentNode = nextNode;
    }
}


void LinkedList::listNodes() {
    Node* currentNode = this->head;
    int linkedListLength = 0;

    if (currentNode->getNext() == nullptr) {
        std::cout << "Lista vazia";
        return;
    }
    while (currentNode != nullptr) {
        if (currentNode != this->head) {
            std::cout << "Monomio: " << currentNode->getFirstValue() << "^" <<  currentNode->getSecondValue() << std::endl;
            linkedListLength++;
        }
        currentNode = currentNode->getNext();
    }

    if (currentNode == nullptr) {
        std::cout << "Lista acabou " << linkedListLength << std::endl;
    }
}
