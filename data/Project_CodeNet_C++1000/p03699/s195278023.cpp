/*
  Contest 063
  C - Bugged
  Rakesh Kumar --> 28/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0, total = 0;
    std::cin >> n;
    std::vector<int> v;
    while (n--) {
        int s = 0;
        std::cin >> s;
        v.emplace_back(s);
        total += s;
    }
    std::sort(v.begin(), v.end());
    if (total % 10 == 0) {
        for (std::size_t i = 0; i < v.size(); ++i) {
            if ((total - v[i]) % 10) {
                std::cout << total - v[i] << std::endl;
                return 0;
            }
        }
        total = 0;
    }
    std::cout << total << std::endl;

    return 0;
}
