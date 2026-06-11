#include <bits/stdc++.h>

using namespace std;

const int N = 2010;
vector<int > G[N];
int n, maxDist;

int visit(int par, int u, int depth) {
    int ans = 1;
    if(depth == maxDist / 2) return ans;
    for(int v: G[u]) {
        if(v != par)
            ans += visit(u, v, depth + 1);
    }
    return ans;
}

int main() {
    //freopen("a.txt", "r", stdin);
    cin >> n >> maxDist;
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans  = n;
    for(int u = 1; u <= n; ++u) {
        int canKeep = 0;
        if(maxDist % 2 == 0) {
            canKeep = visit(0, u, 0);
            ans = min(ans, n - canKeep);
        }
        else {
            for (int v: G[u]) {
                canKeep = visit(u, v, 0) + visit(v, u, 0);
                ans = min(ans, n - canKeep);
            }
        }
    }
    cout << ans << endl;
}