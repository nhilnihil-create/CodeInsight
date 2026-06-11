#include <vector>
#include <bitset>
#include <limits>
#include <iostream>

long long solve(int n, int k, const std::vector<long long> & a) {
    long long cost { std::numeric_limits<long long>::max() };
    for (int i = 0; i < (1 << n); ++i) {
        const std::bitset<15> bits(i);
        if (bits.count() < k) {
            continue;
        }

        long long cur_cost { 0L };
        long long height { 0L };
        for (int j = 0; j < n; ++j) {
            const bool can_build { ((i >> j) & 1) && (a[j] <= height) };
            if (can_build) {
                cur_cost += (height - a[j] + 1);
                ++height;
            }
            height = std::max(height, a[j]);
        }
        cost = std::min(cost, cur_cost);
    }

    return cost;
}

int main() {
    int n;
    int k;
    std::cin >> n >> k;

    const auto a = [&] {
        std::vector<long long> v;
        for (int i = 0; i < n; ++i) {
            long long h;
            std::cin >> h;
            v.push_back(h);
        }
        return v;
    }();

    std::cout << solve(n, k, a) << std::endl;
    return 0;
}
