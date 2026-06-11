#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    vector<vector<int>> b = a;
    rep(k, n) rep(i, n) rep(j, n) b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
    rep(i, n) rep(j, n) if (a[i][j] != b[i][j])
    {
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    rep(i, n) rep(j, n) ans += a[i][j];
    rep(i, n) rep(j, n)
    {
        bool ok = false;
        rep(k, n) if (b[i][j] == b[i][k] + b[k][j] && k != i && k != j) ok = true;
        if (ok)
            ans -= a[i][j];
    }
    cout << ans / 2 << endl;
}