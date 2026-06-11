#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

int INF = 100100100;

int G[110][110];

struct Edge {
    int a, b, c;
};

int main() {
    int N, M;
    cin >> N >> M;
    rep(i, N) {
        rep(j, N) {
            G[i][j] = INF;
        }
        G[i][i] = 0;
    }

    vector<Edge> edges;
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a][b] = c;
        G[b][a] = c;
        edges.push_back(Edge{a, b, c});
    }

    rep(k, N) rep(i, N) rep(j, N) chmin(G[i][j], G[i][k] + G[k][j]);
    int ans = 0;
    rep(i, M) if (G[edges[i].a][edges[i].b] < edges[i].c && G[edges[i].b][edges[i].a] < edges[i].c) ans++;
    cout << ans << endl;
}