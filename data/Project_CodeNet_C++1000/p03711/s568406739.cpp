/*
  Contest 062
  A - Grouping
  Rakesh Kumar --> 28/08/2020
 */

#include <bits/stdc++.h>



int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::vector<int> v1 = {1, 3, 5, 7, 8, 10, 12};
    std::vector<int> v2 = {4, 6, 9 , 11};
    int x = 0, y = 0;
    std::cin >> x >> y;
    if ((std::find(v1.begin(), v1.end(), x) != v1.end() && std::find(v1.begin(), v1.end(), y) != v1.end()) ||
        (std::find(v2.begin(), v2.end(), x) != v2.end() && std::find(v2.begin(), v2.end(), y) != v2.end()))
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    return 0;
}
