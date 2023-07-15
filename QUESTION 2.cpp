/*

You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase **may be** incomplete.

Given the integer n, return *the number of **complete rows** of the staircase you will build*.

*/


#include <iostream>

int arrangeCoins(int n) {
    long left = 1;
    long right = n;

    while (left <= right) {
        long mid = left + (right - left) / 2;
        long totalCoins = (mid * (mid + 1)) / 2;

        if (totalCoins <= n) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return right;
}

int main() {
    int n = 5;
    int completeRows = arrangeCoins(n);

    std::cout << "Number of complete rows: " << completeRows << std::endl;

    return 0;
}
