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
#include <cstring>


int main() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::map<int, int> minid, cnt;
    for (int i = 0; i < n; i++) {
        if (!minid.count(a[i])) minid[a[i]] = i;
        cnt[a[i]]++;
    }
    std::sort(a.rbegin(), a.rend());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    std::vector<long long> ans(n);
    int m = a.size();
    a.push_back(0);
    long long c = 0;
    int mi = 1e9;
    for (int i = 0; i < m; i++) {
        c += cnt[a[i]];
        mi = std::min(mi, minid[a[i]]);
        ans[mi] += c*(a[i] - a[i + 1]);
    }
    for (int i = 0; i < n; i++) std::cout << ans[i] << std::endl;
    return 0;
}
