/*
  B - NarrowRectanglesEasy
  Contest 056
  Rakesh Kumar --> 18/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int w = 0, a = 0, b = 0;
    std::cin >> w >> a >> b;
    int d = 0;
    if (a != 0) {
        if (a < b)
            d = b - (a + w);
        else
            d = a - (b + w);
    }
    if (d < 0)
        d = 0;
    std::cout << d << std::endl;

    return 0;
}
