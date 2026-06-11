/*
  A - Three-letter acronym
  Contest 059
  Rakesh Kumar --> 28/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::string a, b, c, s;
    std::getline(std::cin, s);
    std::istringstream iss(s);
    iss >> a >> b >> c;
    std::cout << static_cast<char>(a[0] - 32)
              << static_cast<char>(b[0] - 32)
              << static_cast<char>(c[0] - 32)
              << std::endl;

    return 0;
}
