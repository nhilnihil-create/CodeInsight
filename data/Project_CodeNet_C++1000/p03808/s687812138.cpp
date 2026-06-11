#include <bits/stdc++.h>
using i64 = long long;

int main() {
    i64 n, s = 0;
    std::cin >> n;
    std::vector<i64> a(n);
    for (auto &e : a) {
        std::cin >> e;
        s += e;
    }
    i64 m = n * (n + 1) / 2;
    if (s % m) {
        std::cout << "NO" << std::endl;
        return 0;
    }
    i64 k = s / m;
    for (int i = 0; i < n; i++) {
        auto d = a[(i + 1) % n] - a[i] - k;
        if (d > 0 || d % n != 0) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }

    std::cout << "YES" << std::endl;

    return 0;
}
