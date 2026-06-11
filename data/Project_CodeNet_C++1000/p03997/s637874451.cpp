/*
  A - Trapezoids
  Contest 045
  Rakesh Kumar --> 02/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int a = 0, b = 0, h = 0;
    std::cin >> a >> b >> h;
    std::cout << (((a + b) * h) >> 1) << std::endl;

    return 0;
}
