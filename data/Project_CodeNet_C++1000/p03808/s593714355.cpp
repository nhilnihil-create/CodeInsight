#include <iostream>
#include <vector>
#include <numeric>

using lint = long long;

void fail() {
    std::cout << "NO" << std::endl;
    std::exit(0);
}

int main() {
    lint N;
    std::cin >> N;

    std::vector<lint> A(N);
    for (auto& a : A) std::cin >> a;
    lint sum = std::accumulate(A.begin(), A.end(), 0LL);

    if (sum % (N * (N + 1) / 2) > 0) fail();

    // 合計操作回数
    lint M = sum / (N * (N + 1) / 2);

    for (lint i = 0; i < N; ++i) {
        lint d = A[(i + 1) % N] - A[i];

        // 箱iの選ばれる回数は(M-d)/Nとなる
        // この値は非負整数でなくてはならない
        if (M < d || (M - d) % N > 0) fail();
    }

    std::cout << "YES" << std::endl;
    return 0;
}
