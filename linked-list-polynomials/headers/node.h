//
// Created by mirla-lopes on 27/11/24.
//

#ifndef NODE_H
#define NODE_H

class Node {

private:
    int firstValue;
    int secondValue;
    Node *next = nullptr;

public:
    Node(int firstValue, int secondValue) : firstValue(firstValue), secondValue(secondValue) {};
    // ~Node();

    int getFirstValue() const;
    int getSecondValue() const;
    void setFirstValue(int firstValue);
    void setSecondValue(int secondValue);


    Node *getNext();
    void setNext(Node *next);

    Node operator+(const Node& rhs) const;
};
#endif //NODE_H
