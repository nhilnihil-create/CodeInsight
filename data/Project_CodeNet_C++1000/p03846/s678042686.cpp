#include <bits/stdc++.h>

int main() {
    uint64_t N;
    std::cin >> N;

    uint64_t cnt[N] = {0};
    uint64_t A[N];
    for (size_t i = 0; i < N; ++i) {
        std::cin >> A[i];
        cnt[A[i]] += 1;
        if (cnt[A[i]] > 2) {
            std::cout << 0 << std::endl;
            return 0;
        }
    }

    if (N % 2 != 0 && cnt[0] != 1) {
        std::cout << 0 << std::endl;
        return 0;
    } 

    for (size_t i = 1; i < N; ++i) {
        if ((cnt[i] == 2 || cnt[i] == 0) == false) {
            std::cout << 0 << std::endl;
            return 0;
        }
    }

    uint64_t ans = 1;
    for (size_t i = 0; i < N / 2; ++i) {
        ans *= 2;
        ans %= 1000000007;
    }

    std::cout << ans << std::endl;

    return 0;
}
