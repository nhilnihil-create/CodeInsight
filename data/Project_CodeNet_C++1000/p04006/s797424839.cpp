#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 4e3 + 13;
int n, x, ans = 1e18;
int kek[N][N];
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
    cin >> n >> x;
    vector<int> in(n), mda;
    for (int i = 0; i < n; i++)
        cin >> in[i];
    mda = in;
    for (int i = 0; i < n; i++)
        mda.push_back(in[i]);
    for (int i = 0; i < n + n; i++)
    {
        kek[i][i] = mda[i];
        for (int j = i + 1; j < n + n; j++)
        {
            kek[i][j] = min(kek[i][j - 1], mda[j]);
        }
    }
    for (int mx = 0; mx < n; mx++)
    {
        int lans = 0;
        for (int i = n; i < n + n; i++)
        {
            lans += kek[i - mx][i];
        }
        ans = min(ans, lans + mx * x);
    }
    cout << ans;
}