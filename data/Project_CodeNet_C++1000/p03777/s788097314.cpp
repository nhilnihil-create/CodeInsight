/*
  A - HonestOrDishonest
  Contest 056
  Rakesh Kumar --> 18/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    char a, b;
    std::cin >> a >> b;
    if (a == 'H')
        std::cout << b << std::endl;
    else
        if (b == 'H')
            std::cout << 'D' << std::endl;
        else
            std::cout << 'H' << std::endl;

    return 0;
}
