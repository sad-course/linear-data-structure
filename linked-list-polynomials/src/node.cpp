//
// Created by mirla-lopes on 27/11/24.
//

#include "node.h"
#include <iostream>

Node::~Node() = default;

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
    return {this->getFirstValue() + rhs.getFirstValue(), (this->getSecondValue())};
}

Node Node::operator-(const Node &rhs) const {
    if (rhs.getSecondValue() != this->getSecondValue()) {
        throw std::runtime_error("Polynomial is empty. Cannot determine degree.");
    }
    return {this->getFirstValue() - rhs.getFirstValue(), (rhs.getSecondValue())};
}

bool Node::operator==(const Node &rhs) const {
    if (rhs.getFirstValue() == this->getFirstValue()){
        if (rhs.getSecondValue() == this->getSecondValue()) {
            return true;
        }
    }
    return false;
}