/*
  A - AtCoder *** Contest
  Contest 048
  Rakesh Kumar --> 03/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::string s;
    std::getline(std::cin, s);
    std::string r;
    r += s[0];
    for (std::size_t i = 1; i < s.size(); ++i)
        if (std::isupper(s[i]) && s[i - 1] == ' ')
            r += s[i];
    std::cout << r << std::endl;

    return 0;
}
