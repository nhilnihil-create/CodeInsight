/*
  Contest 072
  A - Sandglass2
  Rakesh Kumar --> 09/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int x = 0, t = 0;
    std::cin >> x >> t;
    if (x > t)
        std::cout << x - t << std::endl;
    else
        std::cout << 0 << std::endl;

    return 0;
}
