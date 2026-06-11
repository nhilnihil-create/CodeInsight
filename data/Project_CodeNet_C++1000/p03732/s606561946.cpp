#include <bits/stdc++.h>

using namespace std;

#define ll long long
constexpr ll inf = 1e9+7;

vector<ll> Vs[4];

int main () {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, W;
    cin>>N>>W;
    ll W0, V0;
    cin>>W0>>V0;
    Vs[0].push_back(V0);
    for (ll n = 1; n < N; n++) {
        ll W, V;
        cin>>W>>V;
        Vs[W - W0].push_back(V);
    }
    for (ll i = 0; i < 4; i++) sort(begin(Vs[i]), end(Vs[i]), greater<>());

    ll ans = 0;
    for (ll s = 0; s <= Vs[0].size(); s++) {
        for (ll t = 0; t <= Vs[1].size(); t++) {
            for (ll u = 0; u <= Vs[2].size(); u++) {
                for (ll v = 0; v <= Vs[3].size(); v++) {
                    ll w = 0, V = 0;
                    for (ll i = 0; i < s; i++) { w += W0; V += Vs[0][i]; }
                    for (ll j = 0; j < t; j++) { w += W0+1; V += Vs[1][j]; }
                    for (ll k = 0; k < u; k++) { w += W0+2; V += Vs[2][k]; }
                    for (ll l = 0; l < v; l++) { w += W0+3; V += Vs[3][l]; }

                    if (w <= W) ans = max(ans, V);
                }
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}