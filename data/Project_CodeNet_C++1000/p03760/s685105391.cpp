/*
  B - ∵∴∵
  Contest 058
  Rakesh Kumar --> 23/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::string o;
    std::getline(std::cin, o);
    std::string e;
    std::getline(std::cin, e);
    int i = 0, j = 0;
    int c = 0;
    while (i < o.size() && j < e.size()) {
        if (c & 1)
            std::cout << e[i++];
        else
            std::cout << o[j++];
        ++c;
    }

    while (i < e.size())
        std::cout << e[i++];
    while (j < o.size())
        std::cout << o[j++];
    std::cout << std::endl;

    return 0;
}
