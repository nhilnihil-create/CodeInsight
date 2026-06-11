#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>


int main() {
    int n;
    std::cin >> n;
    std::vector<int> l(n);
    std::vector<int> r(n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> l[i] >> r[i];
        ans += r[i] - l[i] + 1;
    }

    std::cout << ans << "\n";
}