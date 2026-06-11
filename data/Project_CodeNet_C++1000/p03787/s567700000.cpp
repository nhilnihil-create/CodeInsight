#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int bip, s[2], col[100001];
vector<int> G[100001];
bitset<100001> vis;

void dfs(int u, int c) {
    vis[u] = 1, col[u] = c, ++s[c];
    for (int v : G[u]) {
        if (!vis[v]) dfs(v, !c);
        else if (col[u] == col[v]) bip = 0;
    }
}

int main() {
    if (fopen("in", "r")) freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0);

    int N, M; cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u, v; cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }

    ll a = 0, b = 0, c = 0;
    for (int u = 1; u <= N; ++u) if (!vis[u]) {
       bip = 1, s[0] = s[1] = 0;
       dfs(u, 0);
       if (!bip) ++c;
       else if (s[1]) ++b;
       else ++a;
    }

    cout << 2*a*N-a*a+2*b*b+2*b*c+c*c;
}