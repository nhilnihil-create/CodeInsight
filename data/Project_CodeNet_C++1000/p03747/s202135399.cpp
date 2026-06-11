#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<ll, ll>;
using namespace std;

template<class t> void vin(vector<t>& v, int n) {
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
}

int main() {
    ll n, l, t;
    cin >> n >> l >> t;
    vector<ll> x(n), w(n);
    rep(i, n) cin >> x[i] >> w[i];
    vector<ll> tmp(n);
    rep(i, n) {
        if (w[i] == 1) tmp[i] = (x[i] + t) % l;
        else tmp[i] = ((x[i]-t)%l+l)%l;
    }
    sort(tmp.begin(), tmp.end());
    ll cur = 0;
    rep(i, n) {
        if (w[i] == 1) cur -= (t-(l-x[i])+l)/l;
        else cur += (t-(x[i]+1)+l)/l;
    }
    cur = (cur%n+n)%n;
    vector<ll> ans(n);
    rep(i, n) ans[(i+cur)%n] = tmp[i];
    rep(i, n) cout << ans[i] << endl;
    return 0;
}
