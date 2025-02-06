//
// Created by mirla-lopes on 05/02/25.
//

#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H
#include "linked_list.h"

template <typename T>
class CircularLinkedList{
protected:
    Node<T>* head;

public:
    CircularLinkedList() {
        this->head=nullptr;
    };
    Node<T>* getHead() {
        return this->head;
    };
    void append(T data) {
        Node<T>* newNode = new Node<T>{data, nullptr};

        if(!this->head) {
            this->head = newNode;
            newNode->next=this->head;
            return;
        }
        Node<T>* currentElement = this->head;
        while(currentElement->next != this->head) {
            currentElement = currentElement->next;
        }
        currentElement->next = newNode;
        newNode->next=this->head;
    };
    void remove(int steps) {
        if(!this->head) {
            std::cerr << "Empty list" <<std::endl;
        }

        Node<T>* targetElement=this->head;
        Node<T>* previousElement=nullptr;

        for (int i=0; i<steps; i++) {
            previousElement=targetElement;
            targetElement = targetElement->next;
        }

        Node<T>* tmp = targetElement;
        if(previousElement == nullptr || targetElement == this->head) {
            Node<T>* current = this->head;

            do{
                current = current->next;
            }while(current->next != this->head);


            current->next=targetElement->next;
            this->head = targetElement->next;
        }

        if(targetElement->next == this->head) {
            previousElement->next=this->head;
        }else {
            previousElement->next=targetElement->next;
        }

        delete tmp;
    }
};
#endif //CIRCULAR_LINKED_LIST_H
