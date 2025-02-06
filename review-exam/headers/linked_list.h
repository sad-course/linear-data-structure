//
// Created by mirla-lopes on 04/02/25.
//
#include "node.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<typename T>
class LinkedList {
private:
    Node<T> *head;

public:
    LinkedList(): head(nullptr) {
    }

    Node<T> *getHead() {
        return this->head;
    }

    void append(T data) {
        Node<T> *newNode = new Node<T>{data, nullptr};

        if (this->head == nullptr) {
            this->head = newNode;
            return;
        }
        Node<T> *current = this->head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    void pushFront(T data) {
        Node<T> *newNode = new Node<T>{data, nullptr};
        if (!this->head) {
            this->head = newNode;
            return;
        }
        newNode->next = this->head;
        this->head = newNode;
    }

    void pop(T data) {
        if (!this->head) {
            std::cout << "Empty list!" << std::endl;
            return;
        }
        Node<T> *current = this->head;
        if (this->head->data == data) {
            this->head = this->head->next;
            delete current;
        } else {
            while (current->next != nullptr) {
                Node<T> *nextElement = current->next;
                if (nextElement->data == data) {
                    current->next = nextElement->next;
                    delete nextElement;
                } else {
                    current = current->next;
                }
            }
        }
    }

    bool search(T data) {
        int index = 0;
        if (!this->head) {
            std::cout << "Empty list!" << std::endl;
            return false;
        }
        if (this->head->data == data) {
            std::cout << "Element found at index=" << index << std::endl;
            return true;
        }
        Node<T> *current = this->head;
        while (current != nullptr) {
            if (current->data == data) {
                std::cout << "Find it in index= " << index << std::endl;
                return true;
            }
            current = current->next;
            index++;
        }
    }

    void removeDuplicate() {
        Node<T> *current = this->head;
        Node<T> *next = current;

        while (current->next != nullptr) {
            while (next->next != nullptr) {
                if (current->data == next->next->data) {
                    Node<T> *temp = next->next;
                    next->next = temp->next;
                    delete temp;
                } else {
                    next = next->next;
                }
            }
            current = current->next;
            next = current->next;
        }
    }
};

#endif //LINKEDLIST_H
