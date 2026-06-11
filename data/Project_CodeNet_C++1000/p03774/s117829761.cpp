#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

ll dis(ll x1, ll y1, ll x2, ll y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n), c(m), d(m);
    rep(i, n){
        cin >> a[i] >> b[i];
    }
    rep(i, m){
        cin >> c[i] >> d[i];
    }

    rep(i, n){
        ll ans_d = LLONG_MAX;
        ll ans = 0;
        for(ll j = m-1; j>=0;j--){
            ll d_ = dis(a[i], b[i], c[j], d[j]);
            if (ans_d >= d_){
                ans_d = d_;
                ans = j+1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
