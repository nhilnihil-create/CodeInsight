#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int N, M;
vector<T> edges;
vector<P> G[110];
int dist[110][110];

vector<int> dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P>> q;
    vector<int> d(N);
    rep(i, N) d[i] = 1000000000;
    d[s] = 0;
    q.push(P(0, s));
    while (!q.empty()) {
        P p = q.top(); q.pop();
        int v = p.second;
        if (d[v]<p.first) continue;
        rep(i, G[v].size()) {
            int nv = G[v][i].first, w = G[v][i].second;
            if (d[nv]>d[v]+w) {
                d[nv] = d[v]+w;
                q.push(P(d[nv], nv));
            }
        }
    }
    return d;
}

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> M;
    rep(i, M) {
        int a, b, c; cin >> a >> b >> c;
        edges.pb(make_tuple(a-1, b-1, c));
        G[a-1].pb(P(b-1, c));
        G[b-1].pb(P(a-1, c));
    }
    rep(i, N) {
        vector<int> d = dijkstra(i);
        rep(j, N) dist[i][j] = d[j];
    }
    int ans = 0;
    rep(i, M) {
        int a = get<0>(edges[i]), b = get<1>(edges[i]), c = get<2>(edges[i]);
        bool flag = true;
        rep(i, N) rep(j, N) {
            if (dist[i][j]==dist[i][a]+c+dist[b][j]) flag = false;
            if (dist[i][j]==dist[i][b]+c+dist[a][j]) flag = false;
        }
        if (flag) ans++;
    }
    cout << ans << endl;
}