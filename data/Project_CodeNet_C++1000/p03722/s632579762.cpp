#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1LL << 60;

struct Edge {
    int from, to;
    long long cost;
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<Edge> E(M);
    for (int i = 0; i < M; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--; b--;
        c *= -1;
        E[i] = Edge{a, b, c};
    }

    vector<long long> dist(N, INF);
    dist[0] = 0;

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M; j++) {
            Edge e = E[j];
            if (dist[e.from] == INF) continue;

            if (dist[e.to] > dist[e.from] + e.cost) {
                dist[e.to] = dist[e.from] + e.cost;
            }
        }
    }

    long long res = dist[N - 1];

    vector<bool> negative(N, false);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            Edge e = E[j];
            if (dist[e.from] == INF) continue;

            if (dist[e.to] > dist[e.from] + e.cost) {
                dist[e.to] = dist[e.from] + e.cost;
                negative[e.to] = true;
            }
            if (negative[e.from]) {
                negative[e.to] = true;
            }
        }
    }

    if (negative[N - 1]) {
        cout << "inf" << endl;
    } else {
        cout << -res << endl;
    }

    return 0;
}

