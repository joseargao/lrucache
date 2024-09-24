#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <list>
#include <unordered_map>
#include <algorithm>

class LRUCache {
    unsigned long capacity;
    std::list<int> itemKeys;  // List to store keys in order of access
    std::unordered_map<int, int> itemMap;  // Map to store key-value pairs

public:
    LRUCache(int capacity);

    int get(int key);
    void put(int key, int value);
};

#endif // LRU_CACHE_H
