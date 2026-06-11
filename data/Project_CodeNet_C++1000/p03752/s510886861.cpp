#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll ans = 1e18;
    for (int bit = 0; bit < (1 << n); ++bit) {
        int bitcnt = 0;
        ll cur = 0, cost = 0;
        for (int i = 0; i < n; ++i) {
            if(bit & (1 << i)) {
                bitcnt++;
                if(cur >= a[i]) {
                    cost += cur + 1 - a[i];
                    cur = max(cur + 1, a[i]);
                }
            }
            cur = max(cur, a[i]);
        }
        if(bitcnt == k) {
            ans = min(ans, cost);
        }
    }
    cout << ans << endl;
}
