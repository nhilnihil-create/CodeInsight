#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define dump(...)
#endif
#define endl "\n"
#define ll long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, x) for (int i = 0; i < (int)(x); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define RREP(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (int i = ((int)(x)); i > 0; i--)
#define INF 2147483647
#define LLINF 9223372036854775807LL
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define pi pair<int, int>
#define ALL(a) (a).begin(), (a).end()
#define BIT(n) (1LL << (n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてからつかうこと
constexpr ll MOD = 1e9 + 7;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
ll A, B, C, D, E, F, G, H, N, M, L, K, P, Q, R, W, X, Y, Z;
string S, T;
ll ans = 0;

template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec)
        is >> x;
    return is;
}

signed main() {
    cin >> N >> W;
    vi w(N), v(N);
    REP(i, N) {
        cin >> w[i] >> v[i];
        if (i == 0)
            X = w[0];
        w[i] -= X;
    }
    vvvi dp(110, vvi(1010, vi(110, -1)));

    REP(i, N + 1) {
        REP(j, 1000) {
            REP(k, N + 1)
            dp[i][j][k] = -1;
        }
    }
    dp[0][0][0] = 0;
    REP(i, N + 1) {
        REP(j, 900) {
            REP(k, N + 1) {
                if (dp[i][j][k] != -1) {
                    dp[i + 1][j + w[i]][k + 1] = max(dp[i + 1][j + w[i]][k + 1], dp[i][j][k] + v[i]);
                    dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
                }
            }
        }
    }
    dump(dp[N][0], X, W);
    REP(j, 1000) {
        REP(k, N + 1) {
            if ((ll)j + X * (ll)k <= W) {
                ans = max(ans, (ll)dp[N][j][k]);
            }
        }
    }
    cout << ans << endl;
}