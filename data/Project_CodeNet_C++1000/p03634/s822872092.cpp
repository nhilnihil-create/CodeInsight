#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

const ll INF = 1LL<<60;

struct edge {
    int to;
    ll cost;
};

int n, t, k;
vector<vector<edge>> tree;
vector<ll> dist;

void dijkstra(int x) {
    priority_queue<P, vector<P>, greater<P>> q;
    q.push(P(0, x));
    dist[x] = 0; 
    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        for (int i = 0; i < tree[v].size(); ++i) {
            int nv = tree[v][i].to, weight = tree[v][i].cost;
            if (dist[nv] <= dist[v] + weight) continue;
            dist[nv] = dist[v] + weight;
            q.push(P(dist[nv], nv));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    tree.resize(n);
    rep(i, n-1) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    cin >> t >> k;
    k--;

    dist.resize(n, INF);
    dijkstra(k);
    
    rep(i, t) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        cout << dist[x] + dist[y] << endl;
    }
}