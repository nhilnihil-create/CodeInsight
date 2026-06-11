#include "bits/stdc++.h"

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    vector<int> mods(m), used(m), pairs(m);
    for (auto &p : mp)
    {
        if (p.second)
        {
            mods[p.first % m] += p.second;
            pairs[p.first % m] += p.second / 2;
        }
    }
    ans += mods[0] / 2;
    for (int i = 1; i <= m / 2; i++)
    {
        if (i * 2 == m)
        {
            ans += mods[i] / 2;
            used[i] = mods[i];
        }
        else
        {
            int y = min(mods[i], mods[m - i]);
            ans += y;
            used[i] = used[m - i] = y;
        }
    }
    for (int i = 1; i < m; i++)
    {
        int z = (mods[i] - used[i]) / 2;
        ans += min(z, pairs[i]);
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}
