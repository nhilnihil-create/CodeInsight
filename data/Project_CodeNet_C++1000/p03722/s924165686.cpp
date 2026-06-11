#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;

struct Edge {
    int from;
    int to;
    int cost;
    Edge(int f, int t, int c) : from(f), to(t), cost(c) {}
};

bool BellmanFord(vector<Edge> &E, vector<ll> &D, int V, int S) {
    D.resize(V, -INF);
    D[S] = 0;

    REP(i, 0, V) {
        for (auto e : E) {
            if (D[e.from] == -INF) continue;
            if (D[e.to] < D[e.from] + e.cost) {
                D[e.to] = D[e.from] + e.cost;
            }
        }
    }


    int inf[V] = {};
    vector<ll> dist(D.size());
    copy(D.begin(), D.end(), dist.begin());
    REP(i, 0, V) {
        for (auto e : E) {
            if (dist[e.from] == -INF) continue;
            if (dist[e.to] < dist[e.from] + e.cost) {
                dist[e.to] = dist[e.from] + e.cost;
                inf[e.to] = true;
            }
            if(inf[e.from]) inf[e.to] = true;
        }
    }


    return !inf[V - 1];
}

int main() {
    int N, M; cin >> N >> M;
    vector<Edge> E;
    REP(i, 0, M) {
        int a, b, c; cin >> a >> b >> c;
        E.push_back(Edge(--a, --b, c));
    }

    vector<ll> D;
    bool ok = BellmanFord(E, D, N, 0);
    if (ok) {
        cout << D[N - 1] << endl;
    } else {
        cout << "inf" << endl;
    }
    return 0;
}