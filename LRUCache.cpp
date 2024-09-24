#include "LRUCache.h"

LRUCache::LRUCache(int capacity) {
    this->capacity = capacity;
}

int LRUCache::get(int key) {
    if (itemMap.find(key) == itemMap.end()) {
        return -1;  // Key not found
    }
    // Move the accessed key to the front of the list
    itemKeys.splice(itemKeys.begin(), itemKeys, std::find(itemKeys.begin(), itemKeys.end(), key));
    return itemMap[key];  // Return the value associated with the key
}

void LRUCache::put(int key, int value) {
    if (itemMap.find(key) != itemMap.end()) {
        // Key exists, update value and move key to front
        itemKeys.splice(itemKeys.begin(), itemKeys, std::find(itemKeys.begin(), itemKeys.end(), key));
        itemMap[key] = value;  // Update the value
        return;
    }

    // Check if the cache is full
    if (itemKeys.size() == capacity) {
        // Remove the least recently used item (back of the list)
        int lruKey = itemKeys.back();  // Get the least recently used key
        itemMap.erase(lruKey);         // Remove it from the map
        itemKeys.pop_back();            // Remove it from the list
    }

    // Insert the new key-value pair
    itemKeys.push_front(key);          // Add new key to the front of the list
    itemMap[key] = value;              // Store key-value pair in the map
}
