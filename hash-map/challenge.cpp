//
// Created by mirla-lopes on 10/12/24.
//

#include <iostream>
#include <unordered_map>
#include <chrono>
#include <vector>

int collatz(long long value, std::unordered_map<long long, int>& hashTableMemo){
  if (value == 1){
    hashTableMemo[value] = 1;
    return 1;
  }

  if (hashTableMemo.find(value) != hashTableMemo.end()){
    return hashTableMemo[value];
  }

  int length = 0;
  if (value % 2 == 0){
      length = 1 +  collatz(value / 2, hashTableMemo);
  }else{
      length = 1 + collatz(((value * 3) + 1), hashTableMemo);
  }

  hashTableMemo[value] = length;
  return length;
}


int collatzWithVector(long long value, std::vector<int>& hashTable) {
    if (value == 1) { return 1; }

    if ((hashTable[value])) {
        return hashTable[value];
    }

    int length = 0;
    if (value % 2 == 0) {
        length = 1 + collatzWithVector(value / 2, hashTable);
    }else {
        length = 1 + collatzWithVector(((value * 3) + 1), hashTable);
    }

    hashTable.insert(hashTable.begin()+value, length);
    return length;
}

int main(){
    std::unordered_map<long long, int> hashTable;
    std::vector<int> cacheVector;
    cacheVector.reserve(1000000);

    long long limit = 1000000;
    int maxLength = 0;
    int number;

    auto start = std::chrono::high_resolution_clock::now();


    for (long long i = 1; i <= limit; i++){
        int length = collatz(i, hashTable);

        if (length > maxLength){
          maxLength = length;
          number = i;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsedTimeHashTable = end - start;

    std::cout << "HASH APPROACH: " << std::endl;
    std::cout << "The number with the biggest sequence: " << number << std::endl;
    std::cout << "Total of hailstone numbers: " << maxLength << std::endl;
    std::cout << "Time elapsed: " << elapsedTimeHashTable.count() << " seconds" << std::endl;

    maxLength = 0;
    number = 0;

    auto start_ = std::chrono::high_resolution_clock::now();

    for (long long i = 1; i <= limit; i++){
        int length = collatzWithVector(i, cacheVector);

        if (length > maxLength){
            maxLength = length;
            number = i;
        }
    }

    auto end_ = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedTimeVector = end_ - start_;

    std::cout << "VECTOR APPROACH: " << std::endl;
    std::cout << "The number with the biggest sequence: " << number << std::endl;
    std::cout << "Total of hailstone numbers: " << maxLength << std::endl;
    std::cout << "Time elapsed: " << elapsedTimeVector.count() << " seconds" << std::endl;
}