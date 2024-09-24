#include <iostream>
#include "LRUCache.h"

void testLRUCache() {
    LRUCache cache(2); // Capacity of 2

    // Test put and get
    cache.put(1, 1);
    cache.put(2, 2);
    std::cout << "Test 1: Get 1 (Expected: 1, Got: " << cache.get(1) << ")\n"; // Should return 1

    // Cache is {1=1, 2=2}
    cache.put(3, 3); // Evicts key 2
    std::cout << "Test 2: Get 2 (Expected: -1, Got: " << cache.get(2) << ")\n"; // Should return -1 (not found)

    // Cache is {1=1, 3=3}
    std::cout << "Test 3: Get 3 (Expected: 3, Got: " << cache.get(3) << ")\n"; // Should return 3

    // Cache is {1=1, 3=3}
    cache.put(4, 4); // Evicts key 1
    std::cout << "Test 4: Get 1 (Expected: -1, Got: " << cache.get(1) << ")\n"; // Should return -1 (not found)

    // Cache is {3=3, 4=4}
    std::cout << "Test 5: Get 3 (Expected: 3, Got: " << cache.get(3) << ")\n"; // Should return 3
    std::cout << "Test 6: Get 4 (Expected: 4, Got: " << cache.get(4) << ")\n"; // Should return 4

    // Additional tests to verify overwriting values
    cache.put(3, 30); // Update key 3
    std::cout << "Test 7: Get 3 (Expected: 30, Got: " << cache.get(3) << ")\n"; // Should return 30

    // Final test for eviction
    cache.put(5, 5); // Evicts key 4
    std::cout << "Test 8: Get 4 (Expected: -1, Got: " << cache.get(4) << ")\n"; // Should return -1 (not found)
}

int main() {
    testLRUCache();
    return 0;
}
