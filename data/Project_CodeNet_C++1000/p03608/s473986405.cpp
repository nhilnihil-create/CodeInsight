#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

typedef long long ll;
typedef pair<ll,int> P;

typedef struct {
    int to;
    long long cost;
} edge;

ll inf = 1e18;

void dijkstra(int n, vector<vector<edge> > &G, int s, vector<ll> &dist) {
    dist.resize(n);
    rep(i,n)    dist[i] = inf;
    dist[s] = 0;
    priority_queue<P> que;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();    que.pop();
        int u = p.second;   ll d = p.first;
        if (dist[u] < d)
            continue;
        
        for (auto e: G[u]) {
            int v = e.to;   ll c = e.cost;

            if (dist[v] <= dist[u] + c)
                continue;

            dist[v] = dist[u] + c;
            que.push(P(dist[v], v));
        }
    }
}

int main() {
    int n,m, r;   cin >> n >> m >> r;
    vector<int> s(r);
    rep(i, r) {
        cin >> s[i];
        s[i]--;
    }
    vector<vector<edge> > G(n);
    rep(i, m) {
        int a, b;   long long c;
        cin >> a >> b >> c;
        edge e1 = {b-1, c}, e2 = {a-1, c};
        G[a-1].push_back(e1);
        G[b-1].push_back(e2);
    }

    vector<vector<ll> > d(n, vector<ll>(n));
    vector<ll> dist;
    for (int i = 0; i < r; i++) {
        dijkstra(n, G, s[i], dist);
        rep(j, r)
            d[s[i]][s[j]] = dist[s[j]];
    }

    sort(s.begin(), s.end());
    ll ans = 1e18;
    do {
        ll tmp = 0;
        rep(i, r-1)
            tmp += d[s[i]][s[i+1]];
        ans = min(ans, tmp);
    }   while (next_permutation(s.begin(), s.end()));
    cout << ans << endl;
    return 0;
}