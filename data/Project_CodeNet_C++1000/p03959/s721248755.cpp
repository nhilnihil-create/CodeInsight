#include <bits/stdc++.h>
using i64 = long long;

int main() {
    constexpr i64 mod = 1000000007;
    int n;
    std::cin >> n;
    std::vector<int> lb(n), a(n), t(n), q(n);
    for (auto &e : t) std::cin >> e;
    for (auto &e : a) std::cin >> e;

    int h = 0;
    for (int i = 0; i < n; i++) {
        if (h != t[i]) q[i] = h = t[i];
        lb[i] = h;
    }

    h = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (h != a[i]) {
            if (q[i] && q[i] != a[i]) {
                std::cout << 0 << std::endl;
                return 0;
            }
            if (!q[i]) q[i] = a[i];
            h = a[i];
        }
        if (q[i] && q[i] > h) {
            std::cout << 0 << std::endl;
            return 0;
        }
        lb[i] = std::min(lb[i], h);
    }

    i64 ret = 1;
    for (int i = 0; i < n; i++) {
        if (q[i]) continue;
        ret = ret * lb[i] % mod;
    }

    std::cout << ret << std::endl;

    return 0;
}
