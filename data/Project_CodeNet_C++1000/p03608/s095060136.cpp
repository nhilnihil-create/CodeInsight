#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int main(void) {
    ll n, m, r;
    cin >> n >> m >> r;

    vector<ll> v(r);
    for(auto &e: v) cin >> e, e--;
    sort(v.begin(), v.end());
    
    vector<vector<ll>> d(n, vector<ll>(n, 1e15));
    for(ll i=0; i<n; i++) d[i][i] = 0;
    for(ll i=0; i<m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        d[a][b] = d[b][a] = min(c, d[a][b]);
    }
    for(ll k=0; k<n; k++)
    for(ll i=0; i<n; i++)
    for(ll j=0; j<n; j++)
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

    ll res = 1e15;
    do {
        ll t = 0;
        for(ll i=0; i<r-1; i++)
            t += d[v[i]][v[i+1]];
        res = min(res, t);
    } while(next_permutation(v.begin(), v.end()));

    cout << res << endl;
}
