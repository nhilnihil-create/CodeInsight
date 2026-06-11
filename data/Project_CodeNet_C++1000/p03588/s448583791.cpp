#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> nums(n);
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i].first >> nums[i].second;
    }
    sort(nums.begin(), nums.end());
    int ans = 0;
    ans += nums[n - 1].first - nums[0].first + 1; // 最小と最大の間の個数
    ans += nums[0].first - 1; // 数列の最大の数値までの個数
    ans += nums[n - 1].second;
    cout << ans << endl;
    return 0;
}