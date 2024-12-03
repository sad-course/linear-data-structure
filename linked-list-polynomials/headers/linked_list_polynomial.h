//
// Created by mirla-lopes on 03/12/24.
//
#include "linked_list.h"
#ifndef LINKED_LIST_POLYNOMIAL_H
#define LINKED_LIST_POLYNOMIAL_H

class LinkedListPolynomial : public LinkedList {
    private:
        Node *head;

    public:
        LinkedListPolynomial();
        ~LinkedListPolynomial();

        void insert(int coefficient, int exponent);
};

#endif //LINKED_LIST_POLYNOMIAL_H
