#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

vector<pair<int, ll>> tree[100010];
ll depth[100010];

void dfs(int v, int p, ll d) {
    depth[v] = d;
    for (auto &e: tree[v]) {
        if (e.first == p) continue;
        dfs(e.first, v, d + e.second);
    }
}

int main() {
    int n;
    cin >> n;

    rep(i, n - 1) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    int q, k;
    cin >> q >> k;
    k--;

    dfs(k, -1, 0);
    rep(i, q) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        cout << depth[x] + depth[y] << endl;
    }

    return 0;
}
