#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    int Q; cin >> Q;
    vector<vector<int>> query(Q, vector<int>(3));
    for(auto &q : query) for(auto &e : q) cin >> e;
    reverse(query.begin(), query.end());
    vector<vector<int>> dp(N, vector<int>(11));
    auto dfs = [&](auto &&dfs, int cur, int d, int c) -> void {
        if(dp[cur][d]) return;
        for(int i = 0; i <= d; ++i)
            if(dp[cur][i] == 0) dp[cur][i] = c;
        for(auto &to : G[cur]) dfs(dfs, to, d - 1, c);
    };
    for(auto &q : query) dfs(dfs, q[0] - 1, q[1], q[2]);
    for(int i = 0; i < N; ++i) cout << dp[i][0] << '\n';
    return 0;
}
