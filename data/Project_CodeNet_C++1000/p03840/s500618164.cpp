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
    std::vector<long long> a(7);
    for (int i = 0; i < 7; i++) std::cin >> a[i];
    long long ans = 0;
    for (int i : {0, 3, 4}) {
        ans += a[i] - (a[i] & 1);
    }
    ans += a[1];
    if (a[0] > 0 && a[3] > 0 && a[4] > 0) {
        for (int i : {0, 3, 4}) {
            a[i]--;
            a[i] -= a[i] & 1;
        }
        ans = std::max(ans, a[0] + a[1] + a[3] + a[4] + 3);
    }
    std::cout << ans << std::endl;
    return 0;
}