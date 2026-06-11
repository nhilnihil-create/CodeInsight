/*
  Contest 067
  B - Snake Toy
  Rakesh Kumar --> 01/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0, k = 0;
    std::cin >> n >> k;
    std::vector<int> v;
    while (n--) {
        int l = 0;
        std::cin >> l;
        v.emplace_back(l);
    }
    std::sort(v.rbegin(), v.rend());
    int max = 0;
    for (int i = 0; i < k; ++i)
        max += v[i];
    std::cout << max << std::endl;

    return 0;
}
