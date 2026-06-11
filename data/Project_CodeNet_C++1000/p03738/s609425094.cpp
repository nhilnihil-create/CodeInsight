/*
  B - Comparison
  Contest 059
  Rakesh Kumar --> 24/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::string a;
    std::string b;
    std::getline(std::cin, a);
    std::getline(std::cin, b);
    if (a.size() > b.size())
        std::cout << "GREATER" << std::endl;
    else if (a.size() < b.size())
        std::cout << "LESS" << std::endl;
    else {
        if (a == b)
            std::cout << "EQUAL" << std::endl;
        else if (a > b)
            std::cout << "GREATER" << std::endl;
        else
            std::cout << "LESS" << std::endl;
    }
    return 0;
}
