#include <bits/stdc++.h>

int main() {
    uint64_t N, M;
    std::cin >> N >> M;

    uint64_t ans = 0;
    if (M < (2 * N)) {
        ans = M / 2;
    } else {
        ans = N + (M - 2 * N) / 4; 
    }

    std::cout << ans << std::endl;

    return 0;
}
