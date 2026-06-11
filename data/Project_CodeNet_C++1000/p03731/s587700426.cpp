#include <bits/stdc++.h>

int main() {
    uint64_t N, T;
    std::cin >> N >> T;

    uint64_t prev = 0, total = 0, t;
    for (size_t i = 0; i < N; ++i) {
        std::cin >> t;
        if (i == 0 || (prev + T) <= t) {
            total += T;
            prev = t;
        } else {
            total += (T - (prev + T - t));
            prev = t;
        }
    }

    std::cout << total << std::endl;

    return 0;
}
