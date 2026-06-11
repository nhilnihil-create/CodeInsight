#include "bits/stdc++.h"
using namespace std;
vector<int> g[101010];

int dfs(int v, int prev) {
        int res = 0;
        for (int u : g[v]) if (u != prev) res ^= dfs(u, v) + 1;
        return res;
}

int main() {
        int n, a, b;
        cin >> n;
        for (int i = 0; i < n - 1; i ++) {
                cin >> a >> b;
                a --, b --;
                g[a].push_back(b);
                g[b].push_back(a);
        }
        cout << (dfs(0, -1) == 0 ? "Bob" : "Alice") << endl;
        return 0;
}

