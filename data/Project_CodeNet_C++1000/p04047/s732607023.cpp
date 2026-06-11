/*
  A - Iroha and Haiku (ABC Edition)
  Contest 042
  Rakesh Kumar --> 02/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0;
    std::cin >> n;
    std::vector<int> v;
    n <<= 1;
    while (n--) {
        int l = 0;
        std::cin >> l;
        v.emplace_back(l);
    }
    std::sort(v.begin(), v.end());
    int sum = 0;
    for (std::size_t i = 0; i < v.size(); i += 2)
        sum += v[i];
    std::cout << sum << std::endl;

    return 0;
}
