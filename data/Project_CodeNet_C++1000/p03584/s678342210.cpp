#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        if((k & a[i]) == a[i]) {
            ans += b[i];
        }
    }
    for(int i = 30, mask = 0; i >= 0; mask |= (1 << i), --i) {
        if(!(k & (1 << i))) continue;
        const int x = k & mask;
        ll tans = 0;
        for(int j = 0; j < n; ++j) {
            if(a[j] & (1 << i)) continue;
            const int y = a[j] & mask;
            if((y & x) == y) {
                tans += b[j];
            }
        }
        ans = max(ans, tans);
    }

    cout << ans << endl;
}
