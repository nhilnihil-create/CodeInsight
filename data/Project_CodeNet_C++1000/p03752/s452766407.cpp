#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];
    ll ans = 1001001001001001001;
    for (int j = 0; j < (1 << n); ++j) {
        ll cost = 0;
        bitset<15> bs(j);
        ll mx = 0;
        vector<ll> copy = h;
        for (int i = 0; i < n; ++i) {
            if (bs.test(i) && copy[i] <= mx) {
                cost += mx - copy[i] + 1;
                copy[i] = mx + 1;
            }
            mx = max(mx, copy[i]);
        }
        int cnt = 0;
        mx = 0;
        for (int l = 0; l < n; ++l) {
            if (mx < copy[l]) {
                cnt++;
                mx = copy[l];
            }
        }
        if (cnt < k) continue;
        ans = min(ans, cost);
    }
    cout << ans << endl;
}
