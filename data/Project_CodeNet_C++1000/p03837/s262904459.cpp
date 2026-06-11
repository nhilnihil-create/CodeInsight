#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;

vector<int> dijkstra(int s, Graph<pii> &G) {
    int N = G.size();
    vector<int> dist(N, 1e9);
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> que;
    que.push({0, s});

    while (!que.empty()) {
        pii p = que.top();
        que.pop();
        int v = p.second;
        if (dist[v] < p.first)
            continue;
        for (auto np : G[v]) {
            int nv = np.first, cost = np.second;
            if (dist[v] + cost < dist[nv]) {
                dist[nv] = dist[v] + cost;
                que.push({dist[nv], nv});
            }
        }
    }

    return dist;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    Graph<pii> G(N);
    Graph<int> dist;
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    for (int i = 0; i < N; ++i)
        dist.push_back(dijkstra(i, G));

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (auto p : G[i]) {
            if (i >= p.first)
                continue;
            if (dist[i][p.first] < p.second)
                ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
