//
// Created by mirla-lopes on 27/11/24.
//

#include "node.h"

// Node::~Node() {
//     delete this;
// }

int Node::getFirstValue() const {
    return this->firstValue;
}

void Node::setFirstValue(int firstValue) {
    this->firstValue = firstValue;
}

int Node::getSecondValue() const {
    return this->secondValue;
}

void Node::setSecondValue(int secondValue) {
    this->secondValue = secondValue;
}

Node *Node::getNext(){
    return this->next;
}

void Node::setNext(Node *next) {
    this->next = next;
}

Node Node::operator+(const Node& rhs) const{
    Node temp(0,0);
    temp.setFirstValue(this->getFirstValue() + rhs.getFirstValue());
    temp.setSecondValue(this->getSecondValue() + rhs.getSecondValue());
    return temp;
}