#include <bits/stdc++.h>
using namespace std;

int solve() {
    int N, a;
    cin >> N;
    vector<vector<int>> G(N);
    for ( int i = 1; i < N; i++ ) {
        cin >> a;
        a--;
        G[i].push_back(a);
        G[a].push_back(i);
    }

    function<int(int,int)> dfs = [&](int v, int p) -> int {
        vector<int> dep;
        for ( int u : G[v] ) {
            if ( u == p ) continue;
            dep.push_back(dfs(u, v));
        }
        sort(dep.begin(), dep.end(), greater<>());
        int m = 0;
        for ( int i = 0; i < dep.size(); i++ ) {
            m = max(m, dep[i] + i + 1);
        }
        return m;
    };
    
    int ans = dfs(0,-1);
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}