#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
typedef tuple<int, int, int> T;

int N, M;
vector<int> G[1010], rG[1010];
vector<T> edges;
bool flag1[1010], flag2[1010];
int dist[1010];

void bfs1() {
    deque<int> q;
    q.pb(0);
    flag1[0] = true;
    
    while (q.size()) {
        int v = q.front(); q.pop_front();
        rep(i, G[v].size()) {
            int nv = G[v][i];
            if (flag1[nv]) continue;
            flag1[nv] = true;
            q.pb(nv);
        }
    }
}

void bfs2() {
    deque<int> q;
    q.pb(N-1);
    flag2[N-1] = true;
    
    while (q.size()) {
        int v = q.front(); q.pop_front();
        rep(i, rG[v].size()) {
            int nv = rG[v][i];
            if (flag2[nv]) continue;
            flag2[nv] = true;
            q.pb(nv);
        }
    }
}

int bellman_ford() {
    rep(i, N) dist[i] = 1000000000000000;
    dist[0] = 0;
    rep(i, N) rep(j, M) {
        int a = get<0>(edges[j]), b = get<1>(edges[j]), c = get<2>(edges[j]);
        if (flag1[a] && flag2[b] && dist[b]>dist[a]+c) {
            dist[b] = dist[a]+c;
            if (i==N-1) return -1000000000000000;
        }
    }
    return dist[N-1];
}

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> M;
    rep(i, M) {
        int a, b, c; cin >> a >> b >> c;
        G[a-1].pb(b-1);
        rG[b-1].pb(a-1);
        edges.pb(make_tuple(a-1, b-1, -c));
    }
    
    rep(i, N) flag1[i] = false;
    rep(i, N) flag2[i] = false;
    bfs1();
    bfs2();
    int ans = -bellman_ford();
    if (ans==1000000000000000) cout << "inf" << endl;
    else cout << ans << endl;
}