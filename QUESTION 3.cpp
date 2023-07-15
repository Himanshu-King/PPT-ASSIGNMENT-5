/*

Given an integer array nums sorted in non-decreasing order, return an array of the squares of 
each number sorted in non-decreasing order.

*/

#include <iostream>
#include <vector>

std::vector<int> sortedSquares(const std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    std::vector<int> result(nums.size(), 0);

    for (int i = nums.size() - 1; i >= 0; i--) {
        if (abs(nums[left]) >= abs(nums[right])) {
            result[i] = nums[left] * nums[left];
            left++;
        } else {
            result[i] = nums[right] * nums[right];
            right--;
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {-4, -1, 0, 3, 10};

    std::vector<int> result = sortedSquares(nums);

    std::cout << "[";
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i];
        if (i != result.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
