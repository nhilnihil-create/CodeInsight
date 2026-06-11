#include <bits/stdc++.h>

int main() {
    uint64_t x;
    std::cin >> x;

    uint64_t ans = (x / 11) * 2;
    const uint64_t r = x % 11;
    if (1 <= r && r <= 6) {
        ans += 1;
    } else if (7 <= r && r <= 10) {
        ans += 2;
    }

    std::printf("%lu\n", ans);

    return 0;
}
