/*
  B - Unhappy Hacking (ABC Edit)
  Contest 043
  Rakesh Kumar --> 02/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::string s;
    std::getline(std::cin, s);
    std::string r = s;
    int i = 0;
    for (char c : s) {
        if (c == 'B')
            i = std::max(0, i - 1);
        else
            r[i++] = c;
    }

    std::cout << r.substr(0, i) << std::endl;

    return 0;
}
