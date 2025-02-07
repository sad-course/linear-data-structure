//
// Created by mirla-lopes on 06/02/25.
//
#include <iostream>
#include <ostream>
#include "circular_linked_list.h"

template<typename T>
std::ostream &operator<<(std::ostream &os, CircularLinkedList<T> &list) {
    Node<T> *current = list.getHead();

    do {
        os << "(" << current->data << ")->";
        current = current->next;
    } while (current != list.getHead());
    os << "nullptr" << std::endl;

    return os;
}

void circularLinkedList(){
    CircularLinkedList<char> persons;
    persons.append('M');
    persons.append('i');
    persons.append('R');
    persons.remove(4);
    persons.remove(5);
    std::cout << persons;

}