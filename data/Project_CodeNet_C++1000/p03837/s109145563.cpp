#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

constexpr int INF = 1e9;
vector<vector<int>> graph, used;

void dijkstra(int s) {
    vector<int> dist(graph.size(), INF), searched(graph.size(), 0), prev(graph.size(), -1);
    priority_queue<pair<int, int>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (pq.size()) {
        int ver = pq.top().second;
        pq.pop();
        if (searched[ver]) continue;
        rep(i, graph.size()) {
            if (!graph[ver][i]) continue;
            int alt = dist[ver] + graph[ver][i];
            if (alt < dist[i]) {
                dist[i] = alt;
                prev[i] = ver;
                pq.push({-alt, i});
            }
        }
        searched[ver] = 1;
    }
    rep(i, graph.size()) {
        if (prev[i] == -1) continue;
        used[i][prev[i]] = 1;
        used[prev[i]][i] = 1;
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    graph = used = vector<vector<int>>(N, vector<int>(N, 0));
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a - 1][b - 1] = c;
        graph[b - 1][a - 1] = c;
    }
    
    rep(i, N) dijkstra(i);
    int cnt = 0;
    rep(i, N) rep(j, N) {
        if (!graph[i][j]) continue;
        if (!used[i][j]) ++cnt;
    }
    cout << cnt / 2 << endl;
    return 0;
}
