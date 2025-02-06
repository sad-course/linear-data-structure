//
// Created by mirla-lopes on 04/02/25.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
struct Node{
    T data;
    Node<T>* next;
};


template <typename T>
class LinkedList{
  public:
    Node<T>* head;
    LinkedList() {
        head = nullptr;
    }
    void append(T data) {
        Node<T>* newNode = new Node<T>{data, nullptr};

        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node<T>* current = head;
        while(current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    void pushFront(T data) {
        Node<T>* newNode = new Node<T>{data, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void pop(T data) {
        if (!head) {
            std::cout << "Empty list!" << std::endl;
            return;
        }
        Node<T>* current = head;
        if (head->data == data) {
            head = head->next;
            delete current;
        }
        else {
            while(current->next != nullptr) {
                Node<T>* nextElement = current->next;
                if (nextElement->data == data) {
                    current->next = nextElement->next;
                    delete nextElement;
                }else {
                    current = current->next;
                }

            }
        }
    }

    bool search(T data) {
        int index=0;
        if(!head) {
            std::cout << "Empty list!" << std::endl;
            return false;
        }
        if (head->data == data) {
            std::cout << "Element found at index=" << index << std::endl;
            return true;
        }
        Node<T>* current = head;
        while(current != nullptr) {
            if (current->data == data) {
                std::cout << "Find it in index= " << index << std::endl;
                return true;
            }
            current = current->next;
            index++;
        }
    }

    void removeDuplicate() {
        Node<T>* current = head;
        Node<T>* next = current;

        while(current->next != nullptr) {
            while(next->next != nullptr) {
                if (current->data == next->next->data) {
                    Node<T>* temp = next->next;
                    next->next = temp->next;
                    delete temp;
                }else {
                    next = next->next;
                }

            }
            current = current->next;
            next = current->next;
        }

    }
};

#endif //LINKEDLIST_H
