#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int n, l, q;
    std::cin >> n;
    std::vector<int> x(n);
    for (auto &e : x) std::cin >> e;
    std::cin >> l >> q;

    constexpr int m = 16;
    std::vector<std::vector<int>> bin(n, std::vector<int>(m + 1, -1));
    for (int i = 0; i < n; i++) {
        bin[i][0] = std::upper_bound(x.begin(), x.end(), x[i] + l) - x.begin();
        bin[i][0]--;
        if (bin[i][0] == i) bin[i][0] = -1;
    }
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
        if (bin[j][i] < 0) continue;
        bin[j][i + 1] = bin[bin[j][i]][i];
    }

    while (q--) {
        int a, b;
        std::cin >> a >> b;
        --a; --b;
        if (a > b) std::swap(a, b);
        int ret = 0;
        for (int i = m; i >= 0; i--) {
            if (bin[a][i] >= 0 && bin[a][i] <= b) {
                ret += 1 << i;
                a = bin[a][i];
            }
        }
        std::cout << (a != b ? 1 : 0) + ret << std::endl;
    }

    return 0;
}
