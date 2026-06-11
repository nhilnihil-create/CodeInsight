#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    n *= 2;
    auto v = std::vector<int>(n);
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];
    std::sort(v.begin(), v.end());
    std::reverse(v.begin(), v.end());
    int res = 0;
    for (size_t i = 0; i + 2 <= v.size(); i += 2)
        res += v[i + 1];
    std::cout << res << std::endl;
    return 0;
}