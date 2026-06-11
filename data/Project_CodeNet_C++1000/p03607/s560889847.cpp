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

    long long ans = 0;
    for (auto itr = as.begin(); itr != as.end(); itr++)
    {
        
        int num = std::upper_bound(a.begin(), a.end(), *itr) - std::lower_bound(a.begin(), a.end(), *itr);
        if(num%2 != 0) {
            ans += num%2;
        }
    }

    std::cout << ans << "\n";
}
