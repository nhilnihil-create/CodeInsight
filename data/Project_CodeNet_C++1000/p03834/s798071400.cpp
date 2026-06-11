/*
  A - Haiku
  Contest 051
  Rakesh Kumar --> 04/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::string s;
    std::getline(std::cin, s);
    for (char c : s)
        if (c == ',')
            std::cout << " ";
        else
            std::cout << c;
    std::cout << std::endl;

    return 0;
}
