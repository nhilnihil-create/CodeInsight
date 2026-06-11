/*
  Contest 061
  Rakesh Kumar --> 28/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    int a = 0, b = 0, c = 0;
    std::cin >> a >> b >> c;
    if (c >= a && c <= b)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    return 0;
}
