/*
  B - Increment Decrement
  Contest 052
  Rakesh Kumar --> 04/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0;
    std::cin >> n;
    std::cin.ignore();
    std::string s;
    std::getline(std::cin, s);

    int x = 0;
    int m = 0;
    for (char c : s) {
        if (c == 'I') ++x;
        else --x;
        m = std::max(x, m);
    }
    std::cout << m << std::endl;

    return 0;
}
