#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N+1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int Q;
    cin >> Q;
    vector<int> v(Q), d(Q), c(Q), ans(N+1, 0);
    for (int i = 0; i < Q; i++) cin >> v[i] >> d[i] >> c[i];
    vector<vector<bool>> used(N+1, vector<bool>(11, false));
    for (int i = Q - 1; i >= 0; i--) {
        if (used[v[i]][d[i]]) continue;
        queue<pair<int, int>> que;
        que.push({v[i], d[i]});
        while (!que.empty()) {
            auto p = que.front();
            que.pop();
            int u = p.first, dist = p.second;
            if (!ans[u]) ans[u] = c[i];
            for (int k = 0; k <= dist; k++) used[u][k] = true;
            if (!dist) continue;
            for (int w : G[u]) {
                if (used[w][dist - 1]) continue;
                que.push({w, dist - 1});
            }
        }
    }
    for (int i = 1; i <= N; i++) cout << ans[i] << '\n';
}