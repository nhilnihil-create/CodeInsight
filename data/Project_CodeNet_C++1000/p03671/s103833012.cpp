/*
  Contest 066
  A - ringring
  Rakesh Kumar --> 01/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int a = 0, b = 0, c = 0;
    std::cin >> a >> b >> c;
    std::cout << std::min(a + b, std::min(b + c, a + c)) << std::endl;

    return 0;
}
