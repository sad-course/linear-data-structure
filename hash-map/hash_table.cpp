//
// Created by mirla-lopes on 09/12/24.
//

#include "headers/hash_table.h"

void HashTable::setSize(int size) {
    this->size = size;
    table.resize(size);
}

int HashTable::getSize() {
    return this->size;
}

int HashTable::hash(int key) {
    return key % size;
}

void HashTable::insert(int key) {
    int index = hash(key);
    for (int val : table[index]) {
        if (val == key) return;
    }
    table[index].push_back(key);
}

bool HashTable::search(int key) {
    int index = hash(key);
    for(int val : table[index]) {
        if (val == key) return true;
    }
    return false;
}
