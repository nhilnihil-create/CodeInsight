#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007LL;

ll mod_inv(ll a, ll m) {
    ll b = m, x = 1, y = 0, s, t;
    while ( b != 0 ) {
        s = y;
        y = x - ( a / b ) * y;
        x = s;
        t = b;
        b = a % b;
        a = t;
    }
    return (x % m + m) % m;
}

ll solve() {
    ll N, M;
    cin >> N >> M;
    ll x, y, xp, yp;
    vector<ll> dx(N-1), dy(M-1);
    for ( int i = 0; i < N; i++ ) {
        cin >> x;
        if ( i > 0 ) dx[i-1] = x - xp;
        xp = x;
    }
    for ( int i = 0; i < M; i++ ) {
        cin >> y;
        if ( i > 0 ) dy[i-1] = y - yp;
        yp = y;
    }

    auto edge_sum = [](vector<ll>& v) {
        ll n = v.size();
        ll n_all = n * (n+1) / 2 % MOD;
        ll s = 0;
        ll inv2 = mod_inv(2,MOD);
        for ( ll i = 0; i < n; i++ ) {
            ll n_ex1 = (n-1-i) * (n-i) / 2 % MOD;
            ll n_ex2 = i * (i+1) / 2 % MOD;
            ll n_c = (n_all + MOD - n_ex1 + MOD - n_ex2) % MOD;
            s += (v[i] * n_c) % MOD;
            s %= MOD;
        }
        return s;
    };

    ll ans = edge_sum(dx) * edge_sum(dy) % MOD;
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}