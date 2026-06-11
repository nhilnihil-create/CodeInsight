/*
  Contest 070
  A - Palindromic Number
  Rakesh Kumar --> 03/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    int n = 0;
    std::cin >> n;
    std::cout << (n / 100 == n % 10 ? "Yes" : "No") << std::endl;

    return 0;
}
