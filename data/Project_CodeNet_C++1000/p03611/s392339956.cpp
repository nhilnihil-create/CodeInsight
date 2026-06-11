#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

int main()
{

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::set<int> as;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        as.insert(a[i]);
    }

    std::sort(a.begin(), a.end());

    int ans = 1;
    for (auto itr = as.begin(); itr != as.end(); itr++)
    {
        int max = std::upper_bound(a.begin(), a.end(), (*itr) + 2) - std::lower_bound(a.begin(), a.end(), (*itr));
        ans = std::max(ans, max);
    }

    std::cout << ans << "\n";
}
