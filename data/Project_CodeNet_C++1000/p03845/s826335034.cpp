/*
  B - Contest with Drinks Easy
  Contest 050
  Rakesh Kumar --> 04/08/2020
 */

#include <bits/stdc++.h>

using ull = unsigned long long int;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0;
    std::cin >> n;

    std::vector<int> v;
    ull total = 0;
    while (n--) {
        int t = 0;
        std::cin >> t;
        total += t;
        v.emplace_back(t);
    }

    int m = 0;
    std::cin >> m;
    while (m--) {
        int p = 0, x = 0;
        std::cin >> p >> x;
        std::cout << total + - v[p - 1] + x << std::endl;
    }

    return 0;
}
