#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<vector<int> > input(int n) {
    vector<vector<int> > G(n);
    for (int i = 0 ;  i< n - 1 ; i++) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    return G;
}
vector<int> bfs(vector<vector<int> > &G, int s) {
    vector<int> d(G.size(), -1);
    queue<int> q; q.push(s); d[s] = 0;
    while (q.size()) {
        int p = q.front(); q.pop();
        for (auto &v : G[p]) {
            if (~d[v])
                continue;
            d[v] = d[p] + 1;
            q.push(v);
        }
    }
    return d;
}
void odd(int n, int k) {
    vector<vector<int> > G = input(n);
    int ans = n;
    for (int u = 0 ; u < n ; u++) {
        for (auto &v : G[u]) {
            vector<int> du = bfs(G, u);
            vector<int> dv = bfs(G, v);
            int cnt = 0;
            for (int j = 0 ; j < n ; j++)
                if (min(du[j], dv[j]) > (k - 1) / 2)
                    cnt++;
            ans = min(ans, cnt);
        }
    }
    cout << ans << '\n';
}
void even(int n, int k) {
    vector<vector<int> > G = input(n);
    int ans = n;
    for (int i = 0 ; i < n ; i++) {
        vector<int> d = bfs(G, i);
        int cnt = 0;
        for (int j = 0 ; j < n ; j++)
            if (d[j] > k / 2)
                cnt++;
        ans = min(cnt, ans);
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    if (k % 2) {
        odd(n, k);
    } else {
        even(n, k);
    }
}
