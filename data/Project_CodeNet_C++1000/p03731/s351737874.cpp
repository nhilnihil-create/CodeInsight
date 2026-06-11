#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll ans = 0;
    rep(i, n - 1) ans += min(a[i + 1] - a[i], t);

    ans += t;
    cout << ans << endl;

    return 0;
}