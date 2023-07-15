/*

Given an integer array nums of length n where all the integers of nums are in the range [1, n] 
and each integer appears **once** or **twice**, return *an array of all the integers that appears 
**twice***.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

*/

#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> findDuplicates(const std::vector<int>& nums) {
    std::unordered_set<int> seen;
    std::vector<int> result;

    for (int num : nums) {
        if (seen.count(num) == 1) {
            result.push_back(num);
        } else {
            seen.insert(num);
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    std::vector<int> duplicates = findDuplicates(nums);

    std::cout << "Duplicates: [";
    for (int i = 0; i < duplicates.size(); i++) {
        std::cout << duplicates[i];
        if (i != duplicates.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
