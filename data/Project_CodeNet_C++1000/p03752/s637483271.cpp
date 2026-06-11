//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

ll n, k;
vector<ll> a(20);

ll solve (vector<ll> &d) {
    ll mx = 0, res = 0, p = 0;
    rep(i, k) {
        while (p < d[i]) {
            mx = max(mx, a[p]);
            p++;
        }
        res += max(mx+1-a[p], 0ll);
        mx = max(mx+1, a[p]);
        p++;
    }
    return res;
}

int main() {
    cin >> n >> k;
    rep(i, n) cin >> a[i];
    ll ans = 1e15;
    rep(i, 1<<n) {
        vector<ll> d;
        rep(j, n) if (i>>j & 1) d.push_back(j);
        sort(all(d));
        if (d.size() != k) continue;
        ans = min(ans, solve(d));
    }
    cout << ans << endl;
    return 0;
}