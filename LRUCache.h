#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <list>
#include <unordered_map>
#include <utility>

class LRUCache {
    unsigned long capacity;
    std::list<std::pair<int, int>> itemList; // Store key-value pairs
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> itemMap; // Map keys to list iterators

public:
    LRUCache(unsigned long capacity);

    int get(int key);
    void put(int key, int value);
};

#endif // LRU_CACHE_H
