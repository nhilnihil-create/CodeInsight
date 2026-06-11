/*
  A - Fighting over Candies
  Contest 047
  Rakesh Kumar --> 03/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int a = 0, b = 0, c = 0;
    std::cin >> a >> b >> c;
    std::vector<int> v = {a, b, c};
    std::sort(v.begin(), v.end());
    if (v[0] + v[1] == v[2])
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    return 0;
}
