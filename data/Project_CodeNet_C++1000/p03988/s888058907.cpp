#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 4e3 + 13;

signed main()
{
#ifdef home
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#else
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> in(n);
    int mx = 0;
    map<int, int> uwu;
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
        mx = max(mx, in[i]);
        uwu[in[i]]++;
    }
    int mn = (mx + 1) / 2;
    if (mx & 1)
    {
        if (uwu[mn] < 2)
        {
            cout << "Impossible";
            return 0;
        }
        uwu[mn] -= 2;
    }
    else
    {
        if (uwu[mn] < 1)
        {
            cout << "Impossible";
            return 0;
        }
        uwu[mn]--;
    }
    for (int i = mn + 1; i <= mx; i++)
    {
        if (uwu[i] < 2)
        {
            cout << "Impossible";
            return 0;
        }
        uwu[i] -= 2;
    }
    for (auto i : uwu)
    {
        if (!i.second)
            continue;
        if (i.first <= mn)
        {
            cout << "Impossible" << '\n';
            return 0;
        }
    }
    cout << "Possible";
}