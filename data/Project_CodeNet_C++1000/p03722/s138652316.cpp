#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;

struct Edge {int to; long long cost;};
struct Bedge { int from, to; long long cost; };

template<class T>
vector<T> Bell(const vector<vector<Edge>> &G, int s, T def) {
    int N = (int)G.size();
    vector<T> dist(N, def);
    vector<bool> negative(N);
    vector<Bedge> edges;
    for(int from = 0; from < N; ++from) {
        for(auto &e : G[from]) edges.push_back({from, e.to, e.cost});
    }
    dist[s] = 0;
    for(int loop = 0; loop < N - 1; ++loop) {
        for(auto &e : edges) {
            if(dist[e.from] == INF) continue;
            if(dist[e.to] > dist[e.from] + e.cost) {
                dist[e.to] = dist[e.from] + e.cost;
            }
        }
    }
    for(int loop = 0; loop < N; ++loop) {
        for(auto &e : edges) {
            if(dist[e.from] == INF) continue;
            if(dist[e.to] > dist[e.from] + e.cost) {
                dist[e.to] = dist[e.from] + e.cost;
                negative[e.to] = true;
            }
            if(negative[e.from]) negative[e.to] = true;
        }
    }
    for(int i = 0; i < N; ++i) {
        if(negative[i]) dist[i] = -INF;
    }
    return dist;
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<Edge>> G(N);
    for(int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        G[a].push_back({b, -c});
    }
    auto dist = Bell(G, 0, INF);
    if(dist[N - 1] == -INF) cout << "inf" << '\n';
    else cout << -dist[N - 1] << '\n';
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
