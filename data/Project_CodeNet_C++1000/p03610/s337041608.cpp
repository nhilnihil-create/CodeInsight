/*
  Contest 072
  A - Sandglass2
  Rakesh Kumar --> 10/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::string s;
    std::getline(std::cin, s);
    for (std::size_t i = 0; i < s.size(); ++i)
        if ((i & 1) == 0)
            std::cout << s[i];
    std::cout << std::endl;

    return 0;
}
