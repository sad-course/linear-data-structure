//
// Created by mirla-lopes on 27/01/25.
//
#include <iostream>
#include "linked_list_polynomial.h"

int main() {
    LinkedListPolynomial list2;

    Node teste(1,9);
    Node teste2(1,9);

    Node result = teste + teste2;

    list2.addNode(-2,2);
    list2.addNode(4,8);
    list2.addNode(3,9);


    list2.listNodes();
    std::cout << "Tamanho: " << list2.getLength() << std::endl;
    std::cout << list2;
    std::cout << "\n" << list2.evaluation(3);
    return 0;
}