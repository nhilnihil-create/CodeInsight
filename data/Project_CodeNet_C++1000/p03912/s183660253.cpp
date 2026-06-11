#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

int main() {
    long long n, m, t, ret = 0;
    std::cin >> n >> m;
    std::vector<std::map<long long, long long>> x(m);
    for (auto i = 0ll; i < n; i++) {
        std::cin >> t;
        x[t % m][t]++;
    }

    auto bo = [](auto acc, auto& p) { return acc + p.second; };

    ret += std::accumulate(x[0].begin(), x[0].end(), 0ll, bo) / 2;
    if (m % 2 == 0) ret += std::accumulate(x[m / 2].begin(), x[m / 2].end(), 0ll, bo) / 2;

    for (auto i = 1; i < (m + 1) / 2; i++) {
        auto ssum = std::accumulate(x[i].begin(), x[i].end(), 0ll, bo);
        auto bsum = std::accumulate(x[m - i].begin(), x[m - i].end(), 0ll, bo);
        if (bsum > ssum) {
            x[i].swap(x[m - i]);
            std::swap(ssum, bsum);
        }
        auto multiels = std::accumulate(x[i].begin(), x[i].end(), 0ll, [](auto acc, auto& el) { return acc + el.second / 2 * 2; });
        if (ssum - multiels >= bsum) {
            ret += bsum + multiels / 2;
        } else {
            ret += bsum + (ssum - bsum) / 2;
        }
    }

    std::cout << ret << std::endl;

    return 0;
}