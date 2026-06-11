#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M, R;
    cin >> N >> M >> R;
    vector<int> r(R);
    REP(i, R) {
        int rr;
        cin >> rr;
        r[i] = rr - 1;
    }
    vector<vector<int>> dist(N, vector<int>(N, INF));
    REP(i, N) dist[i][i] = 0;
    REP(i, M) {
        int A, B, C;
        cin >> A >> B >> C;
        A--; B--;
        dist[A][B] = dist[B][A] = C;
    }
    REP(k, N) REP(i, N) REP(j, N) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    vector<vector<int>> dp(1 << R, vector<int>(R, INF));
    REP(i, R) dp[1 << i][i] = 0;
    REP(S, 1 << R) {
        REP(i, R) {
            if (S >> i & 1 == 0) continue;
            REP(j, R) {
                dp[S | 1 << j][j] = min(dp[S | 1 << j][j], dp[S][i] + dist[r[i]][r[j]]);
            }
        }
    }
    int ans = INF;
    REP(i, R) ans = min(ans, dp[(1 << R) - 1][i]);
    cout << ans << endl;
}