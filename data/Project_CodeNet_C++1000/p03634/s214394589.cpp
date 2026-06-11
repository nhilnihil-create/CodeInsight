#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

struct Edge{
    int to, c;
    Edge(int to, int c):to(to), c(c){}
};

using Graph = vector<vector<Edge>>;

Graph G;
ll dist[100005];

void dfs(int v, int p){
    for(auto e : G[v]){
        if(e.to == p) continue;
        dist[e.to] = dist[v] + e.c;
        dfs(e.to, v);
    }
}

int main(){
    int n; cin >> n;
    G.resize(n);
    rep(i,n-1){
        int a, b, c; cin >> a >> b >> c;
        --a, --b;
        G[a].push_back(Edge(b,c));
        G[b].push_back(Edge(a,c));
    }
    int q, k; cin >> q >> k;
    --k;
    dfs(k, -1);
    rep(i,q){
        int x, y; cin >> x >> y;
        --x, --y;
        ll ans = dist[x] + dist[y];
        cout << ans << endl;
    }
    return 0;
}