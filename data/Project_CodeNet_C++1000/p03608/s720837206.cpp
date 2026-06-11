#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

using Graph = vector<vector<Pll>>;
ll dp[1024][9];

void solve() {
    ll N, M, R;
    cin >> N >> M >> R;
    Vl visit(R);
    for (ll i = 0; i < R; i++) {
        cin >> visit[i];
        --visit[i];
    }

    Graph g(N);
    vector<Vl> cost(N, Vl(N, L_INF));
    for (ll i = 0; i < N; i++) {
        cost[i][i] = 0;
    }
    for (ll i = 0; i < M; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
        cost[a][b] = c;
        cost[b][a] = c;
    }

    for (ll k = 0; k < N; k++) {
        for (ll i = 0; i < N; i++) {
            for (ll j = 0; j < N; j++) {
                if (cost[i][k] != L_INF && cost[k][j] != L_INF) {
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }
    }

    fill_n(&dp[0][0], sizeof(dp) / sizeof(dp[0][0]), L_INF);
    for (ll i = 0; i < R; i++) {
        dp[(1LL << i)][i] = 0;
    }

    for (ll mask = 0; mask < (1LL << R); mask++) {
        for (ll i = 0; i < R; i++) {
            if (!((mask >> i) & 1)) continue;
            for (ll j = 0; j < R; j++) {
                if (!((mask >> j) & 1)) continue;
                ll pmask = mask & ~(1LL << i);
                if (dp[pmask][j] != L_INF && cost[visit[j]][visit[i]] != L_INF)
                    dp[mask][i] = min(dp[mask][i], dp[pmask][j] + cost[visit[j]][visit[i]]);
            }
        }
    }

    ll ans = L_INF;
    for (ll i = 0; i < R; i++) {
        ans = min(ans, dp[(1LL << R) - 1][i]);
    }

    cout << ans << "\n";
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif
#ifdef FILEOUTPUT
    ofstream ofs("./in_out/output.txt");
    cout.rdbuf(ofs.rdbuf());
#endif
    solve();
    cout << flush;
    return 0;
}