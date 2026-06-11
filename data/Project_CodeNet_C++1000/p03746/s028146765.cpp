#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
    int N, M, a, b, v0 = -1;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for ( int i = 0; i < M; i++ ) {
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
        if ( v0 < 0 ) v0 = a;
    }

    vector<vector<int>> pt(2);
    vector<bool> used(N, false);
    function<void(int, int, int)> dfs = [&](int v, int p, int k) {
        used[v] = true;
        pt[k].push_back(v);
        for ( int u : G[v] ) {
            if ( u == p ) continue;
            if ( used[u] ) continue;
            dfs(u, v, k);
            break;
        }
    };

    used[v0] = true;
    {
        int v = G[v0][0];
        dfs(v, v0, 0);
    }
    {
        for ( int i = 1; i < G[v0].size(); i++ ) {
            int v = G[v0][i];
            if ( used[v] ) continue;
            dfs(v, v0, 1);
            break;
        }
    }
    std::reverse(pt[1].begin(), pt[1].end());

    vector<int> ans(pt[1]);
    ans.push_back(v0);
    for ( auto x : pt[0] ) ans.push_back(x);
    cout << ans.size() << "\n";
    for ( int i = 0; i < ans.size(); i++ ) {
        cout << (i != 0 ? " " : "") << ans[i] + 1;
    }
    cout << "\n";
    return 0;
}

int main() {
    solve();
    return 0;
}