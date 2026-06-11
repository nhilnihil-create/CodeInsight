#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll f(ll a, ll b) {
    ll ak = 0, bk = 0;
    while (a) {
        a /= 10;
        ak++;
    }
    while (b) {
        b /= 10;
        bk++;
    }
    ll ret = max(ak, bk);
    return ret;
}

int main()
{
    ll n;
    cin >> n;
    ll ans = 1e9;
    for (ll i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            ll j = n / i;
            ll keta = f(i, j);
            ans = min(ans, keta);
        }
    }
    cout << ans << endl;
    return 0;
}