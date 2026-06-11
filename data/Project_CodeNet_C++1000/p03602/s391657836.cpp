#include "bits/stdc++.h"
using namespace std;
using ll = long long; using pii = pair<int, int>;
const int MOD = (int)1e9 + 7, INF = (1 << 27); const ll INFLL = (1LL << 55);
#define FOR(i,a,b) for(int (i)=(a);i<(int)(b);i++)
#define rep(i,n) FOR(i,0,n)
template<typename T> void dbg(T x) { cout << x << "\n"; }
template<typename T, typename U> static void chmin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void chmax(T &x, U y) { if (x < y) x = y; }



int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n; cin >> n;
    static ll d[333][333];
    rep(i, n) rep(j, n) cin >> d[i][j];

    bool ignore[333][333] = {{0},{0}};
    bool ng = false;
    rep(i, n) FOR(j, i + 1, n) rep(k, n) {
        if (k == i || k == j) continue;
        ll ld = d[i][k] + d[k][j];
        if (ld < d[i][j]) ng = true;
        if (ld == d[i][j]) ignore[i][j] = ignore[j][i] = true;
    }

    ll ans = 0;
    rep(i, n) FOR(j, i + 1, n) if (!ignore[i][j]) ans += d[i][j];
    cout << (ng ? -1 : ans) << endl;
    return 0;
}