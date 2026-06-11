#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> ac;
    std::set<int> as;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        as.insert(a[i]);
    }

    std::sort(a.begin(), a.end());

    int evennum = 0;
    for (auto itr = as.begin(); itr != as.end(); itr++)
    {
        int num = std::upper_bound(a.begin(), a.end(), *itr) - std::lower_bound(a.begin(), a.end(), *itr);

        if (num % 2 == 0)
        {
            evennum++;
        }
    }

    int ans = evennum % 2 ? as.size() - 1 : as.size();

    std::cout << ans << std::endl;
}
