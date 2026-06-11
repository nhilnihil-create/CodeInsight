#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> p(n);

    for (int i = 0; i < n; i++) {
        std::cin >> p[i].first >> p[i].second;
    }

    std::sort(p.begin(), p.end(), std::greater<std::pair<int, int>>());

    std::cout << p[0].first + p[0].second << std::endl;
}
