#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using Edge = pair<int, long long>;
using Graph = vector<vector<Edge> >;

// K  から各点 v への距離 dist[ v ]
void rec(const Graph &G, int v, int p, long long sum, vector<long long> &dist) {
    dist[v] = sum;
    for (auto e : G[v]) {
        if (e.first == p) continue;
        rec(G, e.first, v, sum+e.second, dist);
    }
}

int main() {
    // input
    // N個の頂点 
    int N; cin >> N;
    Graph G(N);
    // 頂点a,b 距離c
    for (int i = 0; i < N-1; ++i) {
        int a, b; long long c; cin >> a >> b >> c;
        --a, --b;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    // x1,y1, 中継地点K
    int Q, K; cin >> Q >> K; --K;
    //  x->K->y の距離
    vector<long long> dist(N, 0);

    // K  から各点 v への距離 dist[ v ]
    rec(G, K, -1, 0, dist);

    // K から x への最短経路長と　K から y への最短経路長をたす
    for (int q = 0; q < Q; ++q) {
        int x, y; cin >> x >> y; --x, --y;
        cout << dist[x] + dist[y] << endl;
    }
}   