#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using ii = pair<int, int>;

vector<int> G[100001];
ii DP[100001][11];

int main() {
    if (fopen("in", "r")) freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0);

    int N, M; cin >> N >> M;
    while (M--) {
        int a, b; cin >> a >> b;
        G[a].push_back(b), G[b].push_back(a);
    }

    int Q; cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int v, d, c; cin >> v >> d >> c;
        DP[v][d] = max(ii(i, c), DP[v][d]);
    }

    for (int d = 10; d > 0; --d)
        for (int u = 1; u <= N; ++u)
            for (int v : G[u]) DP[v][d-1] = max(DP[u][d], DP[v][d-1]);

    for (int u = 1; u <= N; ++u) {
        ii ans(0, 0);
        for (int d = 0; d <= 10; ++d) ans = max(DP[u][d], ans);
        cout << ans.s << '\n';
    }
}