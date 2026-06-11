#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        mp[a]++;
    }

    int ans = 0;
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
    {
        if (itr->second % 2)
        {
            ans++;
        }
    }
    cout << ans << '\n';
    return (0);
}
