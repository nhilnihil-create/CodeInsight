#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include<cmath>

int main() {
    int k, n;
    std::cin >> n >> k;
    std::vector<int> x(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += 2*std::min(std::abs(k - x[i]), x[i]);
    }

    std::cout << ans << "\n";
}