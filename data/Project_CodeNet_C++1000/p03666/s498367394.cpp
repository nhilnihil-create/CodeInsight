#include <iostream>

using lint = long long;

int main() {
    lint N, A, B, C, D;
    std::cin >> N >> A >> B >> C >> D;

    lint diff = B - A;
    for (lint p = 0; p < N; ++p) {
        // p個を正に固定する
        lint min = C * p - D * (N - p - 1);
        lint max = D * p - C * (N - p - 1);
        if (min <= diff && diff <= max) {
            std::cout << "YES" << std::endl;
            return 0;
        }
    }

    std::cout << "NO" << std::endl;
    return 0;
}
