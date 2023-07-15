/*

Convert 1D Array Into 2D Array

You are given a **0-indexed** 1-dimensional (1D) integer array original, and two integers, m and n. You are tasked with creating a 2-dimensional (2D) array with  m rows and n columns using **all** the elements from original.

The elements from indices 0 to n - 1 (**inclusive**) of original should form the first row of the constructed 2D array, the elements from indices n to 2 * n - 1 (**inclusive**) should form the second row of the constructed 2D array, and so on.

Return *an* m x n *2D array constructed according to the above procedure, or an empty 2D array if it is impossible*.

*/

#include <iostream>
#include <vector>

std::vector<std::vector<int>> convertTo2DArray(const std::vector<int>& original, int m, int n) {
    if (original.size() != m * n) {
        return {};
    }

    std::vector<std::vector<int>> result(m, std::vector<int>(n, 0));

    for (int i = 0; i < original.size(); i++) {
        int row = i / n;
        int col = i % n;
        result[row][col] = original[i];
    }

    return result;
}

int main() {
    std::vector<int> original = {1, 2, 3, 4};
    int m = 2;
    int n = 2;

    std::vector<std::vector<int>> result = convertTo2DArray(original, m, n);

    for (int i = 0; i < result.size(); i++) {
        std::cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            std::cout << result[i][j];
            if (j != result[i].size() - 1) {
                std::cout << ",";
            }
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
