/*

Given two **0-indexed** integer arrays nums1 and nums2, return *a list* answer *of size* 2 *where:*

- answer[0] *is a list of all **distinct** integers in* nums1 *which are **not** present in* nums2*.*
- answer[1] *is a list of all **distinct** integers in* nums2 *which are **not** present in* nums1.

**Note** that the integers in the lists may be returned in **any** order.

*/

#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<std::vector<int>> findDisjoint(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::unordered_set<int> set2(nums2.begin(), nums2.end());

    std::vector<int> diff1;
    std::vector<int> diff2;

    for (int num : set1) {
        if (set2.find(num) == set2.end()) {
            diff1.push_back(num);
        }
    }

    for (int num : set2) {
        if (set1.find(num) == set1.end()) {
            diff2.push_back(num);
        }
    }

    std::vector<std::vector<int>> answer = {diff1, diff2};

    return answer;
}

int main() {
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<int> nums2 = {2, 4, 6};

    std::vector<std::vector<int>> result = findDisjoint(nums1, nums2);

    std::cout << "[";
    for (int i = 0; i < result[0].size(); i++) {
        std::cout << result[0][i];
        if (i != result[0].size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "], [";
    for (int i = 0; i < result[1].size(); i++) {
        std::cout << result[1][i];
        if (i != result[1].size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
