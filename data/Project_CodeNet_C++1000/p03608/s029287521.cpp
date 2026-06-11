#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1001001001;
const int MOD = 1000000007;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...)
#define print(...)
#endif

int main() {
    int n, m, r; cin >> n >> m >> r;
    vector<int> a(r);
    rep(i, r) {cin >> a[i]; a[i]--;}
    vector<vector<int>> vec(n, vector<int>(n, INF));
    rep(i, n) vec[i][i] = 0;
    rep(i, m) {
        int u, v, c; cin >> u >> v >> c;
        --u; --v;
        vec[u][v] = vec[v][u] = c;
    }
    print(vec);
    sort(all(a));
    rep(k, n) rep(i, n) rep(j, n) {
        chmin(vec[i][j], vec[i][k]+vec[k][j]);
    }
    ll ans = LLONG_MAX;
    print(vec);
    do {
        debug(a);
        ll tot = 0;
        bool ok = true;
        rep(i, r-1) {
            if (vec[a[i]][a[i+1]]<INF) tot += vec[a[i]][a[i+1]];
            else ok = false;
        }
        if (ok) chmin(ans, tot);
    } while (next_permutation(all(a)));

    cout << ans << endl;
}