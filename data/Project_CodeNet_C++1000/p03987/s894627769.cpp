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
    std::vector<long long> a(n);
    std::vector<int> id(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::iota(id.begin(), id.end(), 0);
    std::sort(id.begin(), id.end(), [&](int i, int j) {
        return a[i] < a[j];
    });
    std::set<int> s;
    s.insert(-1); s.insert(n);
    long long ans = 0;
    for (int i : id) {
        auto iter = s.lower_bound(i);
        int r = *iter;
        int l = *(--iter);
        ans += a[i] * (r - i)*(i - l);
        s.insert(i);
    }
    std::cout << ans << std::endl;
    return 0;
}
