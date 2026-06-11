#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 3e18;

int main() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll ans = INF;
    rep(i, (1 << n)) {
        vector<ll> bit(n);
        rep(j, n) bit[j] = i / (1 << j) % 2;
        ll cnt = 0;
        rep(j, n) cnt += bit[j];
        if (cnt < k) continue;
        ll sum = 0, ma = 0;
        rep(j, n) {
            if (bit[j]) {
                if (ma < a[j]) {
                    ma = a[j];
                }
                else {
                    sum += ma + 1 - a[j];
                    ma = ma + 1;
                }
            }
            ma = max(ma, a[j]);
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
