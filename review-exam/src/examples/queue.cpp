//
// Created by mirla-lopes on 06/02/25.
//
#include <iostream>
#include <ostream>
#include "queue.h"

template<typename T>
std::ostream &operator<<(std::ostream &os, Queue<T> &queue) {
    Node<T> *currentNode = queue.getHead();

    os << "head ->";
    while (currentNode != queue.getTail()) {
        os << "| " << currentNode->data << " ";

        currentNode = currentNode->next;
    }
    os << "| " << currentNode->data << " | <- tail" << std::endl;

    return os;
}

void queueExample() {
    Queue<int> fila;

    fila.push(1);
    fila.push(2);
    fila.push(3);
    fila.push(4);
    fila.push(5);
    fila.push(6);

    fila.pop();
    fila.pop();
    std::cout << fila;
}
