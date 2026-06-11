/*
  Contest 068
  B - Break Number
  Rakesh Kumar --> 01/09/2020
 */

#include <bits/stdc++.h>

/*
  Maths question -->
  Max div by 2 number will be log2(n)
*/

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    int n = 0;
    std::cin >> n;
    std::cout << (1 << static_cast<int>(std::floor(std::log2(n)))) << std::endl;

    return 0;
}
