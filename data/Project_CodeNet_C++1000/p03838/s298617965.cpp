#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 301;
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
    int x, y, by;
    cin >> x >> y;
    by = abs(y);
    int ansm = -1, ansp = -1;
    if (x <= -by)
    {
        ansm = -by - x;
        ansp = min(by - x, ansm+1);
    }
    else if (x <= by)
    {
        ansm = by - x + 1;
        ansp = by - x;
        ansm = min(ansm, 1 + by + x + 1);
        ansp = min(ansp, 1 + by + x);
    }
    else
    {
        ansm = 1 + (-by + x);
        ansp = min(1 + (by + x), 1 + ansm);
    }
    if (y < 0)
        cout << ansm;
    else
        cout << ansp;
}