#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

long get_rest(int x, int y, long d) {
    // x^y % dの剰余を計算

    long rest;
    int i;

    rest = x % d;

    for (i = 1; i < y; i++) {
        rest = (rest * x) % d;
    }

    return rest;
}

int main() {
    int N; std::cin >> N;
    int i, temp, abs_value;
    bool is_feasible = true;
    std::vector<int> A;

    for (i = 0; i < N; i++) {
        std::cin >> temp;
        A.push_back(temp);
    }

    std::sort(A.begin(), A.end());

    if (N % 2 == 0) {
        for (i = 0; i < N; i += 2) {
            if (A[i] != i + 1 || A[i + 1] != i + 1) {
                is_feasible = false;
            }
        }
    } else {
        if (A[0] != 0) is_feasible = false;
        for (i = 1; i < N; i += 2) {
            if (A[i] != i + 1 || A[i + 1] != i + 1) {
                is_feasible = false;
            }
        }
    }

    if (is_feasible) {
        if (N > 1) std::cout << get_rest(2, std::round(N / 2), std::pow(10, 9) + 7);
        else std::cout << "1";
     } else {
        std::cout << "0";
     }

    return 0;
}

