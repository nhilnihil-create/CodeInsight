#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;

constexpr ll INF = 1e15;

int main() {
    int N; cin >> N;
    vector<vector<Pll>> graph(N+1);
    for (int i = 0; i < N-1; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back(Pll(b, c));
        graph[b].push_back(Pll(a, c));
    }
    int Q, K; cin >> Q >> K;
    vector<ll> cost(N+1, INF);
    vector<bool> searched(N+1, false);
    cost[K] = 0;
    priority_queue<Pll> pq;
    pq.push(Pll(0, K));
    while (!pq.empty()) {
        Pll x = pq.top(); pq.pop();
        ll c = x.first, f = x.second;
        if (searched[f]) continue;
        searched[f] = true;
        for (auto y : graph[f]) {
            if (y.second + c < cost[y.first]) {
                pq.push(Pll(y.second + c, y.first));
                cost[y.first] = c + y.second;
            }
        }
    }
    while (Q--) {
        int x, y; cin >> x >> y;
        cout << cost[x] + cost[y] << endl;
    }
}
