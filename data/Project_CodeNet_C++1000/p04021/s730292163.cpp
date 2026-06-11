#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 77;
signed main()
{
#ifdef home
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#else
    // freopen("poly.in", "r", stdin);
    // freopen("poly.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    int n, ans = 0;
    cin >> n;
    vector<int> s;
    set<int> f;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        if (i & 1)
        {
            f.insert(v);
        }
        s.push_back(v);
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0 && f.count(s[i]))
        {
            ans++;
        }
    }
    cout << ans;
}