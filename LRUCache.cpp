#include "LRUCache.h"

LRUCache::LRUCache(unsigned long capacity) {
    this->capacity = capacity;
}

int LRUCache::get(int key) {
    if (itemMap.find(key) == itemMap.end()) {
        return -1; // Key not found
    }
    // Move the accessed item to the front of the list
    itemList.splice(itemList.begin(), itemList, itemMap[key]);
    return itemMap[key]->second; // Return the value
}

void LRUCache::put(int key, int value) {
    if (itemMap.find(key) != itemMap.end()) {
        // Key exists, update the value and move it to the front
        itemList.splice(itemList.begin(), itemList, itemMap[key]);
        itemMap[key]->second = value; // Update the value
        return;
    }

    if (itemMap.size() == capacity) {
        // Cache is full, remove the least recently used item
        itemMap.erase(itemList.back().first);
        itemList.pop_back();
    }

    // Insert the new key-value pair at the front of the list
    itemList.emplace_front(key, value);
    itemMap[key] = itemList.begin(); // Update the map with the new iterator
}
