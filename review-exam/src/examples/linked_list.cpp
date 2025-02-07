//
// Created by mirla-lopes on 06/02/25.
//
#include <iostream>
#include <ostream>
#include "linked_list.h"

template<typename T>
std::ostream &operator<<(std::ostream &os, LinkedList<T> &list) {
    Node<T> *current = list.getHead();
    while (current != nullptr) {
        os << "(" << current->data << ")->";
        current = current->next;
    }
    os << "nullptr" << std::endl;
    return os;
}

void linkedList(){
    LinkedList<int> list;
    list.append(3);
    list.append(3);
    list.append(2);
    list.append(1);
    std::cout << list;

}