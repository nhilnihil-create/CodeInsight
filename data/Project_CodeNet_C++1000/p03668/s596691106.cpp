#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using ii = pair<int, int>;

vector<int> G[100001];

int dfs(int u, int p) {
    int ret = 0;
    for (int v : G[u]) if (v != p) ret ^= (dfs(v, u) + 1);
    return ret;
}

int main() {
    if (fopen("in", "r")) freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0);

    int N; cin >> N;
    for (int i = 1; i < N; ++i) {
        int x, y; cin >> x >> y;
        G[x].push_back(y), G[y].push_back(x);
    }
    cout << (dfs(1, 0) ? "Alice" : "Bob");
}