#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
 
const auto ready = []()
{
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);
    return true;
}();
 
int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> a(50);
    std::vector<std::string> b(50);
    for(int i = 0; i < n; ++i) std::cin >> a[i];
    for(int i = 0; i < m; ++i) std::cin >> b[i];
    int ans = 0;
    for(int i = 0; i <= n - m; ++i)
    {
        for(int j = 0; j <= n - m; ++j)
        {
            bool match = true;
            for(int row = i; row < i + m; ++row)
            {
                for(int col = j; col < j + m; ++col)
                {
                    if(a[row][col] != b[row - i][col - j]) match = false;
                }
            }
            if(match) ++ans;
        }
    }
    if(ans) std::cout << "Yes\n";
    else std::cout << "No\n";
    return 0;
}