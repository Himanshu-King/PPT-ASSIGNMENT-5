/*

An integer array original is transformed into a **doubled** array changed by appending **twice 
the value** of every element in original, and then randomly **shuffling** the resulting array.

Given an array changed, return original *if* changed *is a **doubled** array. If* changed *is not 
a **doubled** array, return an empty array. The elements in* original *may be returned in **any** 
order*.

*/

#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> findOriginalArray(const std::vector<int>& changed) {
    int n = changed.size();
    
    if (n % 2 != 0) {
        return {};  // If the size of changed is odd, it cannot be a valid doubled array
    }
    
    std::unordered_map<int, int> countMap;
    std::vector<int> original;
    
    for (int num : changed) {
        countMap[num]++;
    }
    
    for (int num : changed) {
        if (countMap[num] == 0) {
            continue;  // Skip if the current number has been used before
        }
        
        if (countMap[2 * num] == 0) {
            return {};  // If the double of the current number is not found, it is not a valid doubled array
        }
        
        original.push_back(num);
        countMap[num]--;
        countMap[2 * num]--;
    }
    
    return original;
}

int main() {
    std::vector<int> changed = {1, 3, 4, 2, 6, 8};

    std::vector<int> original = findOriginalArray(changed);

    std::cout << "Original array: [";
    for (int i = 0; i < original.size(); i++) {
        std::cout << original[i];
        if (i != original.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
