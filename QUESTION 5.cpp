/*

Given two integer arrays arr1 and arr2, and the integer d, *return the distance value between the two arrays*.

The distance value is defined as the number of elements arr1[i] such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.

*/

#include <iostream>
#include <vector>
#include <cmath>

int findDistanceValue(const std::vector<int>& arr1, const std::vector<int>& arr2, int d) {
    int distance = 0;

    for (int num : arr1) {
        bool found = false;

        for (int val : arr2) {
            if (std::abs(num - val) <= d) {
                found = true;
                break;
            }
        }

        if (!found) {
            distance++;
        }
    }

    return distance;
}

int main() {
    std::vector<int> arr1 = {4, 5, 8};
    std::vector<int> arr2 = {10, 9, 1, 8};
    int d = 2;

    int distance = findDistanceValue(arr1, arr2, d);

    std::cout << "Distance value: " << distance << std::endl;

    return 0;
}
