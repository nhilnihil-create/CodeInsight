/*
  A - Three-letter acronym
  Contest 059
  Rakesh Kumar --> 24/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::string s;
    std::getline(std::cin, s);
    std::istringstream iss(s);
    std::string t;
    while (iss >> t)
        std::cout << static_cast<char>(t[0] - 32);
    std::cout << std::endl;

    return 0;
}
