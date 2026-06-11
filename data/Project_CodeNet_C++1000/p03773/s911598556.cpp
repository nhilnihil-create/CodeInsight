/*
  A - Remaining Time
  Contest 057
  Rakesh Kumar --> 20/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int a = 0, b = 0;
    std::cin >> a >> b;
    std::cout << (a + b) % 24 << std::endl;

    return 0;
}
