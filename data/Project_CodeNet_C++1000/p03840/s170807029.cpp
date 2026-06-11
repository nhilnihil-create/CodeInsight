#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 1;
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
    int i, o, t, j, l, s, z;
    cin >> i >> o >> t >> j >> l >> s >> z;
    int ans = o * 2;
    int _1 = j, _2 = l, _3 = i, v = min(j, min(l, i));
    if (_1 && _2 && _3)
    {
        ans += 6;
        _1--, _2--, _3--;
    }
    ans += _1 / 2 * 4 + _2 / 2 * 4 + _3 / 2 * 4;
    ans = max(ans, j / 2 * 4 + i / 2 * 4 + l / 2 * 4 + o * 2);
    cout << ans / 2;
}