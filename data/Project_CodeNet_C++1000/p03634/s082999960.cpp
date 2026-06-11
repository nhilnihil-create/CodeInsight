#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<pair<int, ll>>>;

const int INF = 1001001001;
vector<ll> dist;
vector<bool> seen;
Graph G;

void dfs(int v, ll d = 0){
    seen[v] = true;
    dist[v] = d;
    for(auto p : G[v]){
        int nv = p.first;
        ll far = p.second;
        if(seen[nv]) continue;
        dfs(nv, d+far);
    }
}

int main(){
    int n; cin >> n;
    G.resize(n);
    dist.resize(n);
    seen.resize(n, false);
    for(int i = 0; i < n-1; i++){
        int a, b;
        ll c; 
        cin >> a >> b >> c;
        --a; --b;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    int q, k; cin >> q >> k;
    --k;
    dfs(k);
    for(int i = 0; i < q; i++){
        int x, y; cin >> x >> y;
        --x; --y;
        cout << dist[x] + dist[y] << endl;
    }
}