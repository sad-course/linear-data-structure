//
// Created by mirla-lopes on 09/12/24.
//
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include "headers/hash_table.h"



std::vector<std::pair<int, int>> findPairs(const std::vector<int>& list, int target) {
    HashTable hashTable(list.size());
    std::set<std::pair<int, int>> pairs;

    for (int value : list) {
        int complement = target - value;

        if (hashTable.search(complement)) {
            pairs.insert({{std::min(value, complement), std::max(value, complement)}});
        }

        hashTable.insert(value);
    }

    return {pairs.begin(), pairs.end()};
}

// int main() {
//     std::vector<int> numbers;
//     int target;
//
//     std::string entry;
//
//     std::cout << "Type a list of integers separated by commas:" << std::endl;
//     std::cin >> entry;
//
//     std::cout << "Type the target value:" << std::endl;
//     std::cin >> target;
//
//     std::stringstream stringStream(entry);
//     std::string token;
//
//     while(getline(stringStream, token, ',')) {
//         numbers.push_back(std::stoi(token));
//     }
//
//
//     std::vector<std::pair<int, int>> result = findPairs(numbers, target);
//
//     std::cout << "Pares: ";
//     for (const auto& pair : result) {
//         std::cout << "(" << pair.first << ", " << pair.second << ") ";
//     }
//     std::cout << std::endl;
//
//     return 0;
// }