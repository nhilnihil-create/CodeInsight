/*
  Contest 069
  B - i18n
  Rakesh Kumar --> 01/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::string s;
    std::getline(std::cin, s);
    std::cout << s[0] << s.size() - 2 << s[s.size() - 1] << std::endl;

    return 0;
}
