#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int MOD = 1e9 + 7;
#define rep(i, n) for (int i = 0; i < int(n); ++i)

//-------------------ここから回答する-----------------------

void solve(void)
{
    int w, h, n;
    cin >> w >> h >> n;
    vector<int> x(n), y(n), a(n);
    rep(i, n) cin >> x[i] >> y[i] >> a[i];
    vector<vector<bool>> flag(h, vector<bool>(w, true));
    rep(i, n)
    {
        if (a[i] == 1)
            rep(j, h) rep(k, x[i]) flag[j][k] = false;
        if (a[i] == 2)
        {
            rep(j, h)
            {
                for (int k = x[i]; k < w; ++k)
                    flag[j][k] = false;
            }
        }
        if (a[i] == 3)
            rep(j, w) rep(k, y[i]) flag[k][j] = false;
        if (a[i] == 4)
        {
            rep(j, w)
            {
                for (int k = y[i]; k < h; ++k)
                    flag[k][j] = false;
            }
        }
    }
    int ans = 0;
    rep(i, h) rep(j, w) if (flag[h - 1 - i][j]) ans++;
    cout << ans << endl;
}
int main(void)
{
    solve();
}
