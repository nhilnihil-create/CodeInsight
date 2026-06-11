#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> pre(n);
    if(a[0]>x)
        pre[0] = x;
    else
        pre[0] = a[0];

    for (int i = 1; i < n;++i){
        ll now = pre[i - 1] + a[i];
        
        if(now<=x)
            pre[i] = a[i];
        else
            pre[i] = a[i] - (now - x);
    }

    ll ans = 0;
    rep(i, n)
        ans += a[i] - pre[i];

    cout << ans << endl;

    return 0;
}