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

LinkedList::~LinkedList() {
    this->head = nullptr;
}

Node *LinkedList::getNext(Node *node) {
    return node->getNext();
}

int LinkedList::getPolynomialDegree() {
    Node *firstElement = this->head->getNext();
    if (firstElement == nullptr) {
        return 0;
    }
    return firstElement->getSecondValue();
}

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

// Add node and verifying exponent
void LinkedList::addNode(int firstValue, int secondValue) {
    Node *previousElement = this->head;
    Node *nextElement = previousElement->getNext();

    Node *createdNode = new Node(firstValue, secondValue);
    bool is_element_added = false;

    while (!is_element_added) {
        if (nextElement == nullptr) {
            previousElement->setNext(createdNode);
            is_element_added = true;
            break;
        }

        if (createdNode->getSecondValue() > nextElement->getSecondValue()) {
            previousElement->setNext(createdNode);
            createdNode->setNext(nextElement);
            is_element_added = true;
            break;
        }
        previousElement = nextElement;
        nextElement = previousElement->getNext();
    }
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


void LinkedList::listAllElements() {
    Node* currentNode = this->head;
    int linkedListLength = 0;

    if (currentNode->getNext() == nullptr) {
        std::cout << "Lista vazia";
        return;
    }
    while (currentNode != nullptr) {
        if (currentNode != this->head) {
            std::cout << currentNode->getFirstValue() <<  std::endl;
            std::cout << currentNode->getSecondValue() << std::endl;
            linkedListLength++;
        }
        currentNode = currentNode->getNext();
    }

    if (currentNode == nullptr) {
        std::cout << "Lista acabou " << linkedListLength << std::endl;
    }
}


int main() {
    LinkedList list;

    Node teste(1,9);
    Node teste2(1,1);

    Node result = teste + teste2;

    //como vou receber o elemento pra excluir então?
    list.addNode(2,5);
    list.addNode(7,0);
    list.addNode(3,9);


    list.listAllElements();
    std::cout << "Grau: " <<  list.getPolynomialDegree() << std::endl;
    std::cout << "Tamanho: " << list.getLength() << std::endl;
}

