#include <bits/stdc++.h>

int main() {
    uint64_t N;
    std::cin >> N;

    uint64_t pf[N+1] = {0};    
    for (size_t i = 2; i <= N; ++i) {
        uint64_t b = i;
        for (size_t j = 2; j <= N; ++j) {
            while (b % j == 0) {
                b /= j;
                pf[j] += 1;
            }
        }
    }

    uint64_t ans = 1;
    for (size_t i = 0; i < N + 1; ++i) {
        if (pf[i] != 0) {
            ans *= (pf[i] + 1);
            ans %= 1000000007;
        }
    }

    std::printf("%lu\n", ans %= 1000000007);

    return 0;
}
