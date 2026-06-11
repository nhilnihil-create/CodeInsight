#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair< int, int >;

int main() {
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll maxv = 0;
    ll minv = a[0];

    for (int i=1; i<n; ++i) {
        maxv = max(maxv, a[i] - minv);
        minv = min(minv, a[i]);
    }

    ll ans = 0;
    ll maxv2 = 0;
    minv = a[0];
    for (int i=1; i<n; ++i) {
        if (maxv2 < a[i] - minv) {
            if (a[i] - minv == maxv) { ans++; }
            else maxv2 = max(maxv2, a[i] - minv);
        }
        minv = min(minv, a[i]);
    }

    cout << ans << endl;
}
