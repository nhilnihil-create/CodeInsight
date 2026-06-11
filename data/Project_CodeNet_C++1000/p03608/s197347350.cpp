#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 10e15;

ll dist[205][205];
int N, M, R;

vector<vector<ll>> distforbitDP(10, vector<ll>(10, 0));

ll dp[(1 << 10) + 1][10];
ll rec(int bit, int v) {
    if (dp[bit][v] != -1) return dp[bit][v];

    if (bit == (1 << v)) {
        return dp[bit][v] = 0;
    }

    ll res = INF;

    int prev_bit = bit & ~(1 << v);

    for (int u = 0; u < R; ++u) {
        if (!(prev_bit & (1 << u))) continue;

        if (res > rec(prev_bit, u) + distforbitDP[u][v]) {
            res = rec(prev_bit, u) + distforbitDP[u][v];
        }
    }

    return dp[bit][v] = res;
}

int main() {
    cin >> N >> M >> R;

    vector<int> r(R);
    rep(i, R) cin >> r[i], --r[i];

    rep(i, N) rep(j, N) dist[i][j] = INF;

    rep(i, M) {
        int a, b, t;
        cin >> a >> b >> t;
        --a;
        --b;
        dist[a][b] = t;
        dist[b][a] = t;
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
    rep(i, R) rep(j, R) distforbitDP[i][j] = dist[r[i]][r[j]];

    for (int bit = 0; bit < (1 << R); ++bit) {
        for (int v = 0; v < R; ++v) {
            dp[bit][v] = -1;
        }
    }

    ll res = INF;
    for (int v = 0; v < R; ++v) {
        if (res > rec((1 << R) - 1, v)) {
            res = rec((1 << R) - 1, v);
        }
    }
    cout << res << endl;
}