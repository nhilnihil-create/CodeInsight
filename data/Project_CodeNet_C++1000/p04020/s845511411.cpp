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
    for (int i = 0; i < n; i++) std::cin >> a[i];
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] / 2;
        if (i < n - 1 && a[i] & 1 && a[i + 1] > 0) {
            ans++;
            a[i + 1]--;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}

