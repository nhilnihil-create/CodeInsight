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
    std::string s, t; std::cin >> s >> t;
    int n = s.size(), m = t.size();
    std::vector<int> sa(n + 2), sb(n + 2), ta(m + 2), tb(m + 2);
    auto acm = [](const std::string &s, std::vector<int> &v, char c) {
        int n = s.size();
        for (int i = 0; i < n; i++) v[i + 1] += v[i] + (s[i] == c);
    };
    acm(s, sa, 'A'); acm(s, sb, 'B');
    acm(t, ta, 'A'); acm(t, tb, 'B');
    int q; std::cin >> q;
    while (q--) {
        int l1, r1, l2, r2;
        std::cin >> l1 >> r1 >> l2 >> r2;
        int csa = sa[r1] - sa[l1 - 1], csb = sb[r1] - sb[l1 - 1];
        int cta = ta[r2] - ta[l2 - 1], ctb = tb[r2] - tb[l2 - 1];
        int diff = (r2 - l2) - (r1 - l1);
        if (diff < 0) {
            diff *= -1;
            std::swap(csa, cta);
            std::swap(csb, ctb);
        }
        if ((cta - csa + diff) % 3 != 0) {
            std::cout << "NO" << std::endl;
            continue;
        }
        int k = (cta - csa + diff) / 3;
        int u = csa - diff + 3 * k;
        int v = csb + 2 * diff - 3 * k;
        std::cout << (u == cta && v == ctb ? "YES" : "NO") << std::endl;
    }
    return 0;
}