#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

signed main() {
    int n, m;
    cin >> n >> m;
    int a[n];
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    ll sum = 0;
    ll imos[2][2 * m + 1];
    fill(imos[0], imos[2], 0);
    rep(i, n - 1) {
        int l = a[i], r = a[i + 1];
        if (l > r) r += m;
        sum += r - l;
        imos[0][l + 2]--;
        imos[0][r + 1]++;
        imos[1][r + 1] += r - l - 1;
    }
    rep(i, 2 * m) {
        imos[0][i + 1] += imos[0][i];
    }
    rep(i, 2 * m) {
        imos[0][i + 1] += imos[0][i];
    }
    rep(i, 2 * m) {
        imos[1][i + 1] += imos[1][i];
    }
    rep(i, 2 * m) {
        imos[1][i] += imos[0][i];
    }
    ll ans = LINF;
    rep(i, m) {
        ans = min(ans, imos[1][i] + imos[1][m + i] + sum);
    }
    cout << ans << endl;
    return 0;
}