#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    rep(i, 0, M) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> ans;
    vector<bool> visited(N);
    bool fin = false;
    function<void(int)> dfs = [&](int cur) {
        if(fin) return;
        visited[cur] = true;
        ans.push_back(cur);
        bool ok = true;
        for(auto &to : G[cur]) {
            if(!visited[to]) {
                ok = false;
                dfs(to);
            }
        }
        if(ok) fin = true;
    };
    dfs(0);
    reverse(ans.begin(), ans.end());
    ans.pop_back();
    fin = false;
    visited[0] = false;
    dfs(0);
    cout << ans.size() << endl;
    for(auto &a : ans) cout << a + 1 << " ";
    return 0;
}
