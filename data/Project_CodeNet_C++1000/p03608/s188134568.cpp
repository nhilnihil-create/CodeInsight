#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
using Graph = vector<vector<pair<ll, ll>>>;


int main()
{
    ll N, M, R; cin >> N >> M >> R;
    vvll G(N, vll(N, inf));
    rep(i, N) G[i][i] = 0;
    vll r(R); rep(i, R) cin >> r[i], r[i]--;
    rep(i, M) {
        ll a, b, c; cin >> a >> b >> c;
        a--, b--;
        G[a][b] = c;
        G[b][a] = c;
    }

    sort(all(r));
    rep(k, N) rep(start, N) rep(end, N) G[start][end] = min(G[start][end], G[start][k] + G[k][end]);

    ll minn = inf;
    do {
        ll total = 0;
        rep(i, R-1) {
            total += G[r[i]][r[i+1]];
        }
        minn = min(minn, total);
    } while (next_permutation(all(r)));

    cout << minn << endl;
    return 0;
}