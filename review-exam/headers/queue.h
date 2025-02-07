//
// Created by mirla-lopes on 06/02/25.
//
#include "node.h"

#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
class Queue {
private:
    Node<T> *head;
    Node<T> *tail;

public:
    Queue(): head(nullptr), tail(nullptr) {
    };

    Node<T> *getHead() {
        return this->head;
    }

    Node<T> *getTail() {
        return this->tail;
    }

    void push(T data) {
        Node<T> *newNode = new Node<T>{data, nullptr};

        if (this->head == nullptr) {
            this->head = newNode;
            this->tail = newNode;
            return;
        }

        this->tail->next = newNode;
        this->tail = newNode;
    }

    void pop() {
        Node<T> *temp = this->head;
        this->head = this->head->next;

        delete temp;
    }
};
#endif //QUEUE_H
