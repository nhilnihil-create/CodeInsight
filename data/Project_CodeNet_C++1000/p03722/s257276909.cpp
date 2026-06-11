#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

ll const INF = 1LL << 60;
int const MAX_N = 1005;

vector<int> G[MAX_N];
vector<int> rG[MAX_N];
bool ok[MAX_N];
bool rok[MAX_N];
bool use[MAX_N];

void dfs(int v) {
    if(ok[v]) return;
    ok[v] = true;
    for(int nv : G[v]) {
        dfs(nv);
    }
}

void rdfs(int v) {
    if(rok[v]) return;
    rok[v] = true;
    for(int nv : rG[v]) {
        rdfs(nv);
    }
}

bool bellman_ford(vector<tuple<int,int,ll>> &Es, int V, int s, vector<ll> &dist) {
    dist.resize(V,INF);
    dist[s] = 0;
    int cnt = 0;
    while(cnt < V) {
        bool end = true;
        for(auto e : Es) {
            int a,b; ll c;
            tie(a,b,c) = e;
            if(!use[a]) continue;
            if(!use[b]) continue;
            if(dist[a] != INF && dist[b] > dist[a] + c) {
                dist[b] = dist[a] + c;
                end = false;
            };
        }
        if(end) break;
        cnt++;
    }
    return (cnt == V);
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<tuple<int,int,ll>> edges;
    rep(i,m) {
        int a, b; ll c;
        cin >> a >> b >> c;
        a--; b--; c *= -1;
        edges.emplace_back(a,b,c);
        G[a].push_back(b);
        rG[b].push_back(a);
    }

    dfs(0); rdfs(n-1);
    rep(i,n) use[i] = ok[i] & rok[i];

    vector<ll> dist;
    if(bellman_ford(edges, n, 0, dist)) cout << "inf" << endl;
    else cout << -dist[n-1] << endl;
    return 0;
}