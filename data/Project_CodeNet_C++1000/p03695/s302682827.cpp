/*
  Contest 064
  C - Colorful Leaderboard
  Rakesh Kumar --> 31/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0;
    std::cin >> n;
    int b = 0;
    std::vector<bool> v(8, false);
    while (n--) {
        int r = 0;
        std::cin >> r;
        if (r < 3200)
            v[r / 400] = true;
        else
            ++b;
    }

    int a = 0;
    for (bool b : v)
        a += b;
    std::cout << std::max(1, a) << " " << a + b << std::endl;

    return 0;
}
