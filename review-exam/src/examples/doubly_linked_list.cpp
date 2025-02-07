//
// Created by mirla-lopes on 06/02/25.
//
#include <iostream>
#include <ostream>
#include "doubly_linked_list.h"

template<typename T>
std::ostream &operator<<(std::ostream &os, DoublyLinkedList<T> &list) {
    DNode<T> *current = list.getHead();
    while (current != nullptr) {
        os << "(" << current->data << ")<->";
        current = current->next;
    }
    os << "nullptr" << std::endl;
    return os;
}

void doublyLinkedList(){

    DoublyLinkedList<int> doublyList;
    doublyList.append(2);
    doublyList.append(4);
    doublyList.append(3);
    doublyList.append(1);

    std::cout << doublyList;
}