//
// Created by mirla-lopes on 22/01/25.
//
#include <iostream>
#include "linked_list_polynomial.h"

#include <complex>

#include "node.h"

LinkedListPolynomial::LinkedListPolynomial() {
    Node *head = new Node(0, 0);
    this->head = head;
}

//Grau de um polinomio - G/g
int LinkedListPolynomial::getPolynomialDegree() const {
    if (!this->head) {
        throw std::runtime_error("Polynomial is empty. Cannot determine degree.");
    }
    Node *firstElement = this->head->getNext();
    return firstElement->getSecondValue();
}

void LinkedListPolynomial::addNode(int firstValue, int secondValue) {
    bool is_element_added = false;
    Node *previousElement = this->head;
    Node *nextElement = previousElement->getNext();

    Node *createdNode = new Node(firstValue, secondValue);

    while (!is_element_added) {
        if (nextElement == nullptr) {
            previousElement->setNext(createdNode);
            break;
        }

        if (createdNode->getSecondValue() > nextElement->getSecondValue()) {
            previousElement->setNext(createdNode);
            createdNode->setNext(nextElement);
            is_element_added=true;
        }
        if (!is_element_added) {
            previousElement = nextElement;
            nextElement = previousElement->getNext();
        }
    }
}


float LinkedListPolynomial::evaluation(int value) const {
    float result=0;
    Node* monomial = this->head->getNext();

    while (monomial != nullptr) {
        if (monomial->getSecondValue() != 0) {
            result += monomial->getFirstValue() * std::pow(value, monomial->getSecondValue());
        }else {
            result += monomial->getFirstValue();
        }

        monomial = monomial->getNext();
    }

    return result;
}
