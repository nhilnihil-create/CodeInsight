/*
  B - A to Z String
  Contest 054
  Rakesh Kumar --> 04/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::string s;
    std::getline(std::cin, s);
    int i = 0, j = s.size() - 1;
    while (s[i++] != 'A');
    while (s[j--] != 'Z');
    std::cout << j - i + 3 << std::endl;

    return 0;
}
