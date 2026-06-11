#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main() {
    ll n, m, r;
    cin >> n >> m >> r;
    vector<ll> s(r);
    rep(i, 0, r) cin >> s[i];
    rep(i, 0, r) s[i]--;
    const ll inf = 1e12;
    vector< vector<ll> > d(n, vector<ll>(n, inf));
    rep(i, 0, n) d[i][i] = 0;
    rep(i, 0, m) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        if(d[u][v] <= w) continue;
        d[u][v] = w;
        d[v][u] = w;
    }
    rep(i, 0, n){
        rep(j, 0, n){
            rep(k, 0, n){
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }
    ll ans = inf;
    vector<ll> array(r);
    rep(i, 0, r) array[i] = i;
    do {
        ll tmp = 0;
        rep(i, 0, r-1) {
            ll from = array[i], to = array[i+1];
            tmp += d[s[from]][s[to]]; 
        }
        ans = min(ans, tmp);
    } while (next_permutation(array.begin(), array.end()));
    if(ans >= inf) cout << "-1\n";
    else cout << ans << "\n";
    return 0;
}