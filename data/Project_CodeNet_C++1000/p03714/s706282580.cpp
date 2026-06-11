#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

signed main() {
    int n;
    cin >> n;
    ll a[3 * n];
    rep(i, 3 * n) {
        cin >> a[i];
    }
    priority_queue<ll, vector<ll>, greater<ll> > lque;
    ll lsum[3 * n + 1] = {};
    for (int i = 0; i < 3 * n; i++) {
        lsum[i + 1] = lsum[i] + a[i];
        lque.emplace(a[i]);
        if ((int)lque.size() <= n) continue;
        lsum[i + 1] -= lque.top();
        lque.pop();
    }
    ll ans = -LINF;
    priority_queue<ll> rque;
    ll rsum = 0;
    for (int i = 3 * n - 1; i >= n; i--) {
        rsum += a[i];
        rque.emplace(a[i]);
        if ((int)rque.size() > n) {
            rsum -= rque.top();
            rque.pop();
        }
        if (i <= 2 * n) {
            ans = max(ans, lsum[i] - rsum);
        }
    }
    cout << ans << endl;
    return 0;
}