#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define dump(...)
#endif
#define endl "\n"
#define ll long long
#define int ll
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, x) for (int i = 0; i < (int)(x); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define RREP(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (int i = ((int)(x)); i > 0; i--)
#define INF 2147483647
#define LLINF 9223372036854775807LL
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int, int>
#define ALL(a) (a).begin(), (a).end()
#define BIT(n) (1LL << (n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてからつかうこと
constexpr ll MOD = 1e9 + 7;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
ll A, B, C, D, E, F, G, H, N, M, L, K, P, Q, R, W, X, Y, Z;
string S, T;
ll ans = 0;

template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec)
        is >> x;
    return is;
}

//0-indexedに注意
class Graph {
    struct edge {
        int from, to, cost;
        edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
    };

public:
    int verN;
    int edgeN = 0;
    vector<edge> edge_set;
    vector<vector<pair<int, int>>> adj_list;
    Graph(int verN) : verN(verN), adj_list(verN) {}

    void add_directed_edge(int from, int to, int cost = 1) {
        edge_set.push_back(edge(from, to, cost));
        adj_list[from].push_back(make_pair(to, cost));
        edgeN++;
    }

    void add_undirected_edge(int from, int to, int cost = 1) {
        edge_set.push_back(edge(from, to, cost));
        edge_set.push_back(edge(to, from, cost));
        adj_list[from].push_back(make_pair(to, cost));
        adj_list[to].push_back(make_pair(from, cost));
        edgeN += 2;
    }

    bool _cycleDetection(int now, int prev, vector<int> &seen, vector<int> &used, vector<int> &cycle) {
        if (used[now]) {
            return false;
        }
        if (seen[now]) {
            cycle.push_back(now);
            return true;
        }

        seen[now] = true;

        for (auto adj_pair : adj_list[now]) {
            int adj = adj_pair.first;
            if (prev == adj)
                continue;
            bool hasDetected = _cycleDetection(adj, now, seen, used, cycle);
            if (hasDetected) {
                cycle.push_back(now);
                return true;
            }
        }
        used[now] = true;

        seen[now] = false;

        return false;
    }

    bool cycleDetection(vector<int> &cycle) {
        cycle.reserve(N);
        vector<int> seen(N);
        vector<int> used(N);
        for (int start = 0; start < N; start++) {
            bool hasDetected = _cycleDetection(start, -1, seen, used, cycle);
            if (hasDetected) {
                for (int i = 1; i < (int)cycle.size(); i++) {
                    if (cycle[i] == cycle[0]) {
                        cycle.erase(cycle.begin() + i + 1, cycle.end());
                    }
                }
                reverse(cycle.begin(), cycle.end());
                //cycle.pop_back();
                return 1;
            }
        }
        return 0;
    }

    bool bellmanford(int start, vector<int> &d) {
        d.assign(verN, INF);
        for (int i = 0; i < verN; i++) {
            d[i] = INF;
        }
        d[start] = 0;
        for (int i = 0; i < verN; i++) {
            for (int j = 0; j < edgeN; j++) {
                edge e = edge_set[j];
                if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                    d[e.to] = d[e.from] + e.cost;
                    if (i == verN - 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    vector<int> dijkstra(int start) {
        vector<int> d(verN, LLINF);
        d[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> used(verN, 0);
        pq.push(make_pair(0, start));
        while (!pq.empty()) {
            int now = pq.top().second;
            pq.pop();
            used[now] = 1;
            for (auto adj_pair : adj_list[now]) {
                int adj = adj_pair.first;
                int dist = adj_pair.second;
                if (used[adj])
                    continue;
                if (d[adj] > d[now] + dist) {
                    d[adj] = d[now] + dist;
                    pq.push(make_pair(d[adj], adj));
                }
            }
        }
        return d;
    }

    vector<vector<int>> warshallfloyd() {
        vector<vector<int>> d(verN, vector<int>(verN, INF));
        for (int i = 0; i < verN; i++) {
            for (auto adj_pair : adj_list[i]) {
                int adj = adj_pair.first;
                int dist = adj_pair.second;
                d[i][adj] = dist;
            }
        }
        for (int i = 0; i < verN; i++) {
            d[i][i] = 0;
        }
        for (int k = 0; k < verN; k++) {         // 経由する頂点
            for (int i = 0; i < verN; i++) {     // 始点
                for (int j = 0; j < verN; j++) { // 終点
                    if (d[i][k] != INF && d[k][j] != INF)
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        return d;
    }
};

signed main() {
    cin >> N;
    Graph g(N);
    REP(i, N - 1) {
        cin >> A >> B >> C;
        A--, B--;
        g.add_undirected_edge(A, B, C);
    }
    cin >> Q >> K;
    K--;
    auto d = g.dijkstra(K);
    REP(i, Q) {
        cin >> X >> Y;
        X--, Y--;
        cout << d[X] + d[Y] << endl;
    }
}