//
// Created by mirla-lopes on 06/02/25.
//
#include <iostream>
#include <ostream>
#include "stack.h"
#include <map>
#include <vector>


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

bool isExpressionBalanced(std::string &expression) {
    Stack<char> stack_brackets;
    std::string opening_brackets = "{[(";
    std::string closing_brackets = "}])";

    std::map<char, char> bracket_corresponding_to =
    {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (auto &ch: expression) {
        if (opening_brackets.find(ch) != std::string::npos) {
            stack_brackets.push(ch);
        }
        if (closing_brackets.find(ch) != std::string::npos) {
            if (stack_brackets.getHead() == nullptr || stack_brackets.peek() != bracket_corresponding_to[ch]) {
                return false;
            }
            stack_brackets.pop();
        }
    }
    bool result = true;
    if (stack_brackets.getHead() != nullptr) {
        result = false;
    }
    return result;
}

void stack(){
    std::vector<std::string> expressions = {
        "(a + b)",
        "{[a * (b + c)]}",
        "a + {b - [c * d]}",
        "a + (b",
        "{[a * b]",
        "(a + b)}",
        "a + {b - [c * d}"
    };

    for (auto &element: expressions) {
        if (isExpressionBalanced(element))
            std::cout << element << " \033[0;32m Expressão correta \033[0m" << std::endl;
        else
            std::cout << element << " \033[0;31m Expressão incorreta \033[0m" << std::endl;
    };
}