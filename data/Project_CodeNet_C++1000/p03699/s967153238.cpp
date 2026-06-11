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
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    int m = std::accumulate(a.begin(), a.end(), 0);
    std::vector<int> cnt(m + 2);
    cnt[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = m - a[i]; j >= 0; j--) {
            cnt[j + a[i]] += cnt[j];
        }
    }
    int ans = 0;
    for (int i = 0; i <= m; i++) {
        if (i % 10 == 0 || cnt[i] == 0) continue;
        ans = i;
    }
    std::cout << ans << std::endl;
    return 0;
}