/*
  Contest 061
  B - Counting Roads
  Rakesh Kumar --> 28/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0, m = 0;
    std::cin >> n >> m;
    std::vector<int> praant(n, 0);
    while (m--) {
        int a = 0, b = 0;
        std::cin >> a >> b;
        ++praant[a - 1];
        ++praant[b - 1];
    }
    for (auto sadake : praant)
        std::cout << sadake << std::endl;

    return 0;
}
