#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <functional>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define REP(i, n) for (int i = 1; i < (int)(n); ++i)
using namespace std;
using lint = int64_t;

constexpr lint INF = 1000000000000000000;
struct Edge {int from; int to; lint cost;};
using Graph = vector<vector<Edge>>;

int main() {
    int N, M;
    cin >> N >> M;
    Graph G(N);
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        G[b].push_back(Edge{b, a, -c});
    }
    vector<int> d(N, 0);
    queue<int> q;
    d[N - 1] = 1;
    q.push(N - 1);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto e : G[v]) {
            if (d[e.to] == 0) {
                d[e.to] = 1;
                q.push(e.to);
            }
        }
    }
    vector<Edge> Edges;
    rep(i, N) {
        for (auto e : G[i]) {
            if (d[i] && d[e.to]) {
                Edges.push_back(Edge{e.to, e.from, e.cost});
            }
        }
    }
    vector<lint> dist(N, INF);
    dist[0] = 0;
    rep(i, N) {
        for (auto e : Edges) {
            if (dist[e.from] + e.cost < dist[e.to]) {
                dist[e.to] = dist[e.from] + e.cost;
                if (i == N - 1) {
                    cout << "inf\n";
                    return 0;
                }
            }
        }
    }
    cout << -dist[N - 1] << "\n";
    return 0;
}
