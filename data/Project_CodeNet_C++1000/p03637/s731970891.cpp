/*
  Contest 069
  C - 4-adjacent
  Rakesh Kumar --> 01/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0;
    std::cin >> n;
    int a = 0, b = 0, c = 0;
    while (n--) {
        int e = 0;
        std::cin >> e;
        if (e % 4 == 0) ++a;
        else if (e % 2 == 0) ++b;
        else ++c;
    }

    if (b == 0) ++a;
    std::cout << (c <= a ? "Yes" : "No") << std::endl;
}
