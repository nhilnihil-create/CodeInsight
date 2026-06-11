#include <bits/stdc++.h>

int main() {
    int64_t N;
    std::cin >> N;

    int64_t A[N];
    for (int64_t i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    int64_t ans = 0;
    for (int64_t i = 0; i < N; ++i) {
        if (A[i] == 0) {
            continue;
        }

        ans += A[i] / 2;

        if ((A[i] % 2 != 0) && (i < (N - 1)) && (A[i + 1] > 0)) {
            A[i] -= 1;
            A[i+1] -= 1;
            ans += 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
