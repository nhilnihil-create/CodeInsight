#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <complex>
#include <iomanip>
#include <cassert>
#include <random>


int main() {
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int>>
        a(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
            a[i][j]--;
        }
    }
    bool used[303] = {};
    auto func = [&](auto &self, int pos = 0) -> int {
        if (pos >= m) return 1e9;
        std::vector<int> cnt(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (used[a[i][j]]) continue;
                cnt[a[i][j]]++;
                break;
            }
        }
        int ma = 0, p = 0;
        for (int i = 0; i < m; i++) {
            if (ma < cnt[i]) {
                ma = cnt[i];
                p = i;
            }
        }
        used[p] = true;
        return std::min(ma, self(self, pos + 1));
    };
    std::cout << func(func) << std::endl;
    return 0;
}
