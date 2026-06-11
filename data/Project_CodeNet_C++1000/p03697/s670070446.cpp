/*
  Contest 063
  A - Restricted
  Rakesh Kumar --> 28/08/2020
 */

#include <bits/stdc++.h>



int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int a = 0, b = 0;
    std::cin >> a >> b;
    if (a + b < 10)
        std::cout << a + b << std::endl;
    else
        std::cout << "error" << std::endl;

    return 0;
}
