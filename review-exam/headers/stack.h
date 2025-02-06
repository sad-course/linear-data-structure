//
// Created by mirla-lopes on 06/02/25.
//
#include "node.h"

#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack {
private:
    Node<T> *head;
    Node<T> *tail;

public:
    Stack() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    Node<T> *getHead() {
        return this->head;
    }

    Node<T> *getTail() {
        return this->tail;
    }

    void push(T data) {
        Node<T> *createdNode = new Node<T>{data, nullptr};
        if (!this->tail) {
            this->head = createdNode;
            this->tail = createdNode;
        }
        createdNode->next = head;
        head = createdNode;
    };

    void pop() {
        if (!this->tail) {
            std::cerr << "Empty stack!" << std::endl;
        }
        Node<T> *tmp = head;
        head = tmp->next;
        delete tmp;
    }
};

#endif //STACK_H
