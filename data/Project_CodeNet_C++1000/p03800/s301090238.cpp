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
    std::string s; std::cin >> s;
    std::string ans;
    auto func = [&](int a, int b) {
        int prev = a, cur = b;
        ans.clear();
        ans += a ? 'W' : 'S';
        ans += b ? 'W' : 'S';
        for (int i = 1; i < n; i++) {
            if ((s[i] == 'o')^cur) {
                std::tie(prev, cur) = std::make_pair(cur, prev);
            }
            else {
                std::tie(prev, cur) = std::make_pair(cur, 1 - prev);
            }
            if (i < n - 1) ans += cur ? 'W' : 'S';
        }
        bool flag;
        if ((s[0] == 'o') ^ cur) flag = prev == b;
        else flag = prev != b;
        return flag && cur == a;
    };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (func(i, j)) {
                std::cout << ans << std::endl;
                return 0;
            }
        }
    }
    std::cout << -1 << std::endl;
    return 0;
}
