/*
  Contest 065
  A - Expired?
  Rakesh Kumar --> 31/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int x = 0, a = 0, b = 0;
    std::cin >> x >> a >> b;
    if (b - a <= 0)
        std::cout << "delicious" << std::endl;
    else if (b - a <= x)
        std::cout << "safe" << std::endl;
    else
        std::cout << "dangerous" << std::endl;

    return 0;
}
