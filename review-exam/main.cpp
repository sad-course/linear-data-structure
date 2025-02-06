#include <iostream>
#include "headers/linked_list.h"
#include "headers/doubly_linked_list.h"
#include "headers/circular_linked_list.h"
#include "headers/stack.h"
#include <sstream>

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

template<typename T>
std::ostream &operator<<(std::ostream &os, Stack<T> &stack) {
    Node<T> *head = stack.getHead();

    while (head != stack.getTail()) {
        if (head == stack.getHead()) {
            os << "| " << head->data << " | <- head" << std::endl;
        } else {
            os << "| " << head->data << " |" << std::endl;
        }
        head = head->next;
    }
    os << "| " << head->data << " | <- tail \n\n";
    return os;
}

int main() {
    DoublyLinkedList<int> doublyList;
    doublyList.append(2);
    doublyList.append(4);
    doublyList.append(3);
    doublyList.append(1);

    std::cout << doublyList;

    LinkedList<int> list;
    list.append(3);
    list.append(3);
    list.append(2);
    list.append(1);
    std::cout << list;


    CircularLinkedList<char> persons;
    persons.append('M');
    persons.append('i');
    persons.append('R');
    persons.remove(4);
    persons.remove(5);
    std::cout << persons;

    Stack<char> charStack;
    std::string stringValue;
    std::cin >> stringValue;

    for (auto &ch: stringValue) {
        charStack.push(ch);
    }
    std::cout << charStack;

    charStack.pop();
    charStack.pop();
    charStack.pop();


    charStack.push('M');
    charStack.push('A');
    std::cout << charStack;

    return 0;
}
