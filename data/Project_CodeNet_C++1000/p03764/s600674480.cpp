#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (signed i = 0; i < (n); i++)
#define REP(i, s, n) for (signed i = (s); i < (n); i++)
#define int long long

signed main() {
    int N, M; cin >> N >> M;
    vector<int> x(N), y(M);
    rep(i, N) cin >> x[i];
    rep(i, M) cin >> y[i];
    const int MOD = 1e9 + 7;
    int hs = 0, ws = 0;
    REP(i, 1, N) hs = (hs + (x[i] - x[0])) % MOD;
    REP(i, 1, M) ws = (ws + (y[i] - y[0])) % MOD;
    int H = hs, W = ws;
    rep(i, N - 1) {
        H = (H + hs) % MOD;
        int sub = -(x[i + 1] - x[i]) * (N - 1 - i);
        sub = sub + (sub / MOD + 1) * MOD;
        (H += sub) %= MOD;
        (hs += sub) %= MOD;
    }
    rep(i, M - 1) {
        W = (W + ws) % MOD;
        int sub = -(y[i + 1] - y[i]) * (M - 1 - i);
        sub = sub + (sub / MOD + 1) * MOD;
        (W += sub) %= MOD;
        (ws += sub) %= MOD;
    }
    
    cout << (H * W) % MOD << endl;
}