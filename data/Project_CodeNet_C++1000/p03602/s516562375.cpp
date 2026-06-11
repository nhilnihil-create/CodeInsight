#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (signed i = 0; i < (n); i++)
#define REP(i, s, n) for (signed i = (s); i < (n); i++)
#define int long long

signed main() {
    int N; cin >> N;
    vector<vector<int>> v(N, vector<int>(N));
    int sum = 0;
    rep(i, N) rep(j, N) cin >> v[i][j];
    
    bool ok = true;
    auto vv = v;
    rep(k, N) rep(i, N) rep(j, N) {
        if (i == k || j == k) continue;
        if (v[i][j] > v[i][k] + v[k][j]) ok = false;
        if (v[i][j] == v[i][k] + v[k][j]) vv[i][j] = 0;
    }
    rep(i, N) rep(j, N) sum += vv[i][j];
    
    cout << (!ok ? -1ll : sum/2) << endl;
}