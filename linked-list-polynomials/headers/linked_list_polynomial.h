//
// Created by mirla-lopes on 03/12/24.
//
#include "linked_list.h"
#ifndef LINKED_LIST_POLYNOMIAL_H
#define LINKED_LIST_POLYNOMIAL_H

class LinkedListPolynomial : public LinkedList {
public:
    LinkedListPolynomial();
    void addNode(int coefficient, int exponent) override;
    int getPolynomialDegree() const;

    float evaluation(int value) const;
    int mergePolynomials(LinkedListPolynomial* firstPolynomial, LinkedListPolynomial* secondPolynomial) const;

    friend std::ostream& operator<<(std::ostream &os, LinkedListPolynomial &list);
};


// friend function é um recurso utilitário para conseguir acessar atributos protegidos e privados de um escopo
inline std::ostream& operator<<(std::ostream &os, LinkedListPolynomial &list) {
    Node* currentNode = list.head;

    while(currentNode != nullptr) {
        os << "(" << currentNode->getFirstValue() << ", " << currentNode->getSecondValue() << ")";
        currentNode = currentNode->getNext();
        if (currentNode != nullptr) {
            os << " -> ";
        }
    }
    return os;
}
#endif //LINKED_LIST_POLYNOMIAL_H
