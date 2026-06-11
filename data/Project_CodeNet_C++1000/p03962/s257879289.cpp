/*
  A - AtCoDeer and Paint Cans
  Contest 046
  Rakesh Kumar --> 03/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int a = 0, b = 0, c = 0;
    std::cin >> a >> b >> c;
    std::set<int> cans = {a, b, c};
    std::cout << cans.size() << std::endl;

    return 0;
}
