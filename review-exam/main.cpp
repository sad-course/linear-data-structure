#include <iostream>
#include "headers/linked_list.h"
#include "headers/doubly_linked_list.h"
#include "headers/circular_linked_list.h"

template <typename T>
std::ostream& operator<<(std::ostream& os, LinkedList<T>& list) {
    Node<T>* current = list.head;
    while (current != nullptr) {
        os << current->data << " ";
        current = current->next;
    }
    os << "nullptr" << std::endl;
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, DoublyLinkedList<T>& list) {
    DNode<T>* current = list.head;
    while (current != nullptr) {
        os << "("<< current->data << ")->";
        current = current->next;
    }
    os << "nullptr" << std::endl;
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, CircularLinkedList<T>& list) {
    Node<T>* current = list.getHead();

    do{
        os << "("<< current->data << ")->";
        current = current->next;
    }while(current != list.getHead());

    os << "nullptr" << std::endl;
    return os;
}
int main() {

    DoublyLinkedList<int> doublyList;
    doublyList.append(2);
    doublyList.append(4);
    doublyList.append(3);

    std::cout << doublyList;


    CircularLinkedList<char> persons;
    persons.append('M');
    persons.append('i');
    persons.append('R');
    persons.remove(4);
    persons.remove(5);

    std::cout << persons;
    return 0;
}
