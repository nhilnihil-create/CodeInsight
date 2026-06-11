/*
  Contest 063
  B - Varied
  Rakesh Kumar --> 28/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::string s, d(26, '0');
    std::getline(std::cin, s);
    std::string r = "yes";
    for (char c : s) {
        if (d[c - 'a'] == '0') {
            d[c - 'a'] = '1';
        } else {
            r = "no";
            break;
        }
    }
    std::cout << r << std::endl;

    return 0;
}
