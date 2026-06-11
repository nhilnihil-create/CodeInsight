/*
  A - Tak and Hotels (ABC Edit)
  Contest 044
  Rakesh Kumar --> 02/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::vector<int> v(26, 0);
    std::string s;
    std::getline(std::cin, s);
    for (char c : s)
        ++v[c - 'a'];

    std::string res = "Yes";
    for (int c : v) {
        if ((c & 1) == 1) {
            res = "No";
            break;
        }
    }
    std::cout << res << std::endl;

    return 0;
}
