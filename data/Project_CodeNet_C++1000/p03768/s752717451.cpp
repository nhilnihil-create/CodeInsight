#include <bits/stdc++.h>
using namespace std;
using iii = tuple<int, int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
void cxxio() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}
#define forn(i,n) for (int i=0; i<int(n); ++i)
#define pb push_back

vvi adj;
vi color;
vi dist;

void dfs(int v, int d, int c) {
    if (!color[v]) color[v]=c;
    if (dist[v]>=d) return;
    dist[v]=d;
    for (int u:adj[v])
        dfs(u, d-1, c);
}

int main() {
    cxxio();
    int n, m;
    cin>>n>>m;
    adj.resize(n);
    color.resize(n);
    dist.resize(n);
    while (m--) {
        int a, b;
        cin>>a>>b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int q;
    cin>>q;
    vector<iii> qs;
    forn(i, q) {
        int v, d, c;
        cin>>v>>d>>c;
        v--;
        qs.pb(iii(v, d, c));
    }
    while (!qs.empty()) {
        int v, d, c;
        tie(v, d, c)=qs.back();
        qs.pop_back();
        dfs(v, d, c);
    }
    for (int c:color)
        cout<<c<<'\n';
}
