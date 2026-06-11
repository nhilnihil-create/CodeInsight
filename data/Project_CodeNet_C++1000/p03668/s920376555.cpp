#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    function<int(int, int)> dfs = [&] (int v, int p) {
        int res = 0;
        for(auto to : g[v]) {
            if(to == p) continue;
            res ^= dfs(to, v) + 1;
        }
        return res;
    };

    cout << (dfs(0, -1) ? "Alice" : "Bob") << endl;
}
