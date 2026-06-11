#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    ll a[7];
    rep(i, 7) cin >> a[i];
    ll ans = a[1] + a[0] / 2 * 2 + a[3] / 2 * 2 + a[4] / 2 * 2;
    if (a[0] > 0 && a[3] > 0 && a[4] > 0) {
        ans = max(ans, a[1] + 3 + (a[0] - 1) / 2 * 2 + (a[3] - 1) / 2 * 2 + (a[4] - 1) / 2 * 2);
    }
    cout << ans << "\n";
}