/*
  Contest 071
  A - Meal Delivery
  Rakesh Kumar --> 09/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int x = 0, a = 0, b = 0;
    std::cin >> x >> a >> b;
    if (std::abs(x - a) < std::abs(x - b))
        std::cout << "A" << std::endl;
    else
        std::cout << "B" << std::endl;

    return 0;
}
