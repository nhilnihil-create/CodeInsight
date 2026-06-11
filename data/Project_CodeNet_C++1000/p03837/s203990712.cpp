#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

struct edge {
    int to, cost, num;
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<edge>> graph(N);
    vector<vector<ll>> dist(N, vector<ll>(N, 1e18));
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        graph[a].push_back(edge({b, c, i}));
        graph[b].push_back(edge({a, c, i}));
        dist[a][b] = c;
        dist[b][a] = c;
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    set<int> used;
    for (int i = 0; i < N; i++) {
        for (auto e : graph[i]) {
            int j = e.to;
            if (dist[i][j] == e.cost) {
                used.insert(e.num);
            }
        }
    }

    cout << M - (int)used.size() << endl;
}
