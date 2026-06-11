#include <bits/stdc++.h>

int main() {
    int32_t n;
    std::cin >> n;

    std::vector< int32_t > l(2 * n);
    for(int32_t i = 0; i < 2 * n; i++) {
        std::cin >> l[i];
    }

    std::sort(l.begin(), l.end());

    int32_t ans = 0;
    for(int32_t i = 0; i < 2 * n; i += 2) {
        ans += l[i];
    }

    std::cout << ans << '\n';
}