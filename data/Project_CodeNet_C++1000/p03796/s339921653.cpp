/*
  B - Training Camp
  Contest 055
  Rakesh Kumar --> 16/08/2020
 */

#include <bits/stdc++.h>

using ull = unsigned long long int;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    ull n = 0;
    std::cin >> n;
    ull power = 1;
    for (int i = 1; i <= n; ++i)
        power = (power *= i) % static_cast<int>(((1e+9) + 7));
    std::cout << power << std::endl;

    return 0;
}
