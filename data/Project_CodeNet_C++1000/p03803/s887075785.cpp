/*
  A - ABC/ARC
  Contest 054
  Rakesh Kumar --> 04/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int a = 0, b = 0;
    std::cin >> a >> b;
    if (a == 1) a = 14;
    if (b == 1) b = 14;
    if (a > b)
        std::cout << "Alice" << std::endl;
    else if (a < b)
        std::cout << "Bob" << std::endl;
    else
        std::cout << "Draw" << std::endl;

    return 0;
}
