//
// Created by mirla-lopes on 13/11/24.
//

#include "headers/linked_list.h"
#include <iostream>

Node::Node(int firstValue, int secondValue) {
    this->firstValue = firstValue;
    this->secondValue = secondValue;
}


int Node::getFirstValue(){
    return this->firstValue;
}

void Node::setFirstValue(int firstValue) {
    this->firstValue = firstValue;
}

int Node::getSecondValue() {
    return this->secondValue;
}

void Node::setSecondValue(int secondValue) {
    this->secondValue = secondValue;
}

Node *Node::getNext() {
    return this->next;
}

void Node::setNext(Node &next) {
    this->next = &next;
}


LinkedList::LinkedList() {
    Node* head = new Node(0, 0);
    this->head = head;
}

/*
 * The function receive a node object as parameter
 *
 * get the current node and the address from the newNode to set in the prevNodde
 *
 */
void LinkedList::addNode(Node &node) {
    Node* head = this->head;
    Node* addressNewNode = &node;

    Node *currentNode = head;
    while (currentNode->getNext() != nullptr) {
        currentNode = currentNode->getNext();
    }
    //if node is null
    if (currentNode->getNext() == nullptr) {
        std::cout << "é o 'ultimo' no";
        currentNode->setNext(*addressNewNode);
        return;
    }
    //start from head node
}

void LinkedList::listElements() {
    Node* currentNode = this->head;
    int linkedListLength = 0;

    if (currentNode->getNext() == nullptr) {
        std::cout << "Lista vazia";
        return;
    }
    while (currentNode != nullptr) {
        std::cout << currentNode->getFirstValue() <<  std::endl;
        std::cout << currentNode->getSecondValue() << std::endl;
        currentNode = currentNode->getNext();

        linkedListLength++;
    }

    if (currentNode == nullptr) {
        std::cout << "Lista acabou " << linkedListLength << std::endl;
    }
}


int main() {
    LinkedList list;
    Node *newNode = new Node(10, 2);
    Node *newNode2 = new Node(10, 3);

    list.addNode(*newNode);
    list.addNode(*newNode2);
    list.listElements();
}

