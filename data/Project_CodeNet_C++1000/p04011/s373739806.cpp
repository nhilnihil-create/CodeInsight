/*
  A - Tak and Hotels (ABC Edit)
  Contest 044
  Rakesh Kumar --> 02/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0, k = 0, x = 0, y = 0;
    std::cin >> n >> k >> x >> y;
    int total = 0;
    for (int i = 0; i < std::min(n, k); ++i)
        total += x;
    for (int i = 0; i < std::max(0, n - k); ++i) {
        total += y;
    }
    std::cout << total << std::endl;

    return 0;
}
