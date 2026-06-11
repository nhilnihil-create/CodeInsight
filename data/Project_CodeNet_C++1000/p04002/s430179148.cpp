#include <bits/stdc++.h>
using i64 = long long;

int main() {
    i64 h, w, n;
    std::cin >> h >> w >> n;
    std::vector<std::pair<i64, i64>> v;
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        v.emplace_back(x, y);
    }

    std::sort(v.begin(), v.end());
    std::vector<i64> ret(10);
    int p[5][5];
    auto check = [&](i64 x, i64 y) {
        if (x <= 0 || x > h || y <= 0 || y > w) return -1;
        auto it = std::lower_bound(v.begin(), v.end(), std::make_pair(x, y));
        return it != v.end() && it->first == x && it->second == y ? 1 : 0;
    };

    for (const auto &e : v) {
        for (int i = -2; i <= 2; i++) for (int j = -2; j <= 2; j++) {
            p[i + 2][j + 2] = check(e.first + i, e.second + j);
        }
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
            int cnt = 0;
            for (int r = 0; r < 3; r++) for (int c = 0; c < 3; c++) {
                if (p[i + r][j + c] < 0) goto next;
                cnt += p[i + r][j + c];
            }
            ret[cnt]++;
next:;
        }
    }

    i64 sum = 0;
    for (int i = 1; i < 10; i++) {
        ret[i] /= i;
        sum += ret[i];
    }

    ret[0] = (w - 2) * (h - 2) - sum;

    for (auto e : ret) std::cout << e << std::endl;

    return 0;
}
