//
// Created by mirla-lopes on 09/12/24.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>


class HashTable {
    private:
        int size;

        std::vector<std::vector<int>> table;
        int hash(int key);
    public:
        HashTable(int size) : size(size), table(size){};


        void setSize(int size);
        int getSize();
        void insert(int key);
        bool search(int key);
};



#endif //HASHTABLE_H
