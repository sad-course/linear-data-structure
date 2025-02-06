//
// Created by mirla-lopes on 04/02/25.
//

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include <iostream>
#include <ostream>
#include "node.h"

template<typename T>
class DoublyLinkedList {
private:
  DNode<T> *head;

public:
  DoublyLinkedList(): head(nullptr) {}

  DNode<T> *getHead() {
    return this->head;
  }

  void append(T data) {
    DNode<T> *newNode = new DNode<T>{data, nullptr, nullptr};
    if (!this->head) {
      this->head = newNode;
      return;
    }
    DNode<T> *previousElement = this->head;
    DNode<T> *nextElement = previousElement->next;


    while (true) {
      //fim & inicio
      if (nextElement == nullptr) {
        if (newNode->data <= previousElement->data) {
          newNode->next = previousElement;
          previousElement->prev = newNode;
          if (this->head == previousElement) {
            this->head = newNode;
          }
          break;
        }
        previousElement->next = newNode;
        newNode->prev = previousElement;
        break;
      }

      //antes
      if (newNode->data <= previousElement->data) {
        previousElement->prev = newNode;
        newNode->next = previousElement;
        if (this->head == previousElement) {
          this->head = newNode;
        }
        break;
      }
      //meio
      if (newNode->data <= nextElement->data) {
        newNode->next = nextElement;
        newNode->prev = previousElement;
        previousElement->next = newNode;
        nextElement->prev = newNode;
        break;
      }
      previousElement = nextElement;
      nextElement = nextElement->next;
    }
  }

  void pop(T data) {
    if (!this->head) {
      std::cerr << "Empty list" << std::endl;
      return;
    }
    DNode<T> *currentElement = this->head;
    DNode<T> *nextElement = currentElement->next;
    while (true) {
      if (nextElement == nullptr) {
        if (currentElement->data == data) {
          if (currentElement->prev == nullptr) {
            delete currentElement;
            this->head = nullptr;
            break;
          }
          currentElement->prev->next = nullptr;
          break;
        }
        std::cerr << "Not found" << std::endl;
        break;
      }

      if (currentElement->data == data) {
        if (currentElement->prev == nullptr) {
          this->head = currentElement->next;
          delete currentElement;
          break;
        }
        DNode<T> *temp = currentElement;
        temp->prev->next = nextElement;
        nextElement->prev = temp->prev;
        delete temp;
        break;
      }

      currentElement = nextElement;
      nextElement = currentElement->next;
    }
  }
};

#endif //DOUBLY_LINKED_LIST_H
