/*
  Contest 067
  A - Sharing Cookies
  Rakesh Kumar --> 01/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int a = 0, b = 0;
    std::cin >> a >> b;
    if (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0)
        std::cout << "Possible" << std::endl;
    else
        std::cout << "Impossible" << std::endl;

    return 0;
}
