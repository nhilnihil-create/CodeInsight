#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=int(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using ll = long long;

class lca {
  public:
    using Graph = vector<vector<pair<ll,int>>>;
    const int n = 0;
    const int log2_n = 0;
    std::vector<std::vector<int>> parent;
    std::vector<int> depth;

    lca() {}

    lca(const Graph &g, int root)
        : n(g.size()), log2_n(log2(n) + 1), parent(log2_n, std::vector<int>(n)), depth(n) {
        dfs(g, root, -1, 0);
        for (int k = 0; k + 1 < log2_n; k++) {
            for (int v = 0; v < (int)g.size(); v++) {
                if (parent[k][v] < 0)
                    parent[k + 1][v] = -1;
                else
                    parent[k + 1][v] = parent[k][parent[k][v]];
            }
        }
    }

    void dfs(const Graph &g, int v, int p, int d) {
        parent[0][v] = p;
        depth[v] = d;
        REP(j,g[v].size()) {
            if (g[v][j].second != p) dfs(g, g[v][j].second, v, d + 1);
        }
    }

    int get(int u, int v) {
        if (depth[u] > depth[v]) std::swap(u, v);
        for (int k = 0; k < log2_n; k++) {
            if ((depth[v] - depth[u]) >> k & 1) {
                v = parent[k][v];
            }
        }
        if (u == v) return u;
        for (int k = log2_n - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
};


int main(){
    int N;cin>>N;
    using P = pair<ll,int>;
    vector<vector<P>> graph(N);
    REP(i,N-1){
        int a,b,c; cin>>a>>b>>c;
        a--;b--;
        graph[a].push_back(P(c,b));
        graph[b].push_back(P(c,a));
    }
    int Q,K;cin>>Q>>K;
    K--;
    vector<ll> dist(N);
    function<void(int,int,ll)> dfs =[&](int u,int prev,ll len){
        dist[u] = len;
        for(auto v:graph[u]){
            if(v.second==prev) continue;
            dfs(v.second,u,len+v.first);
        }
    };
    dfs(K,-1,0);
    lca L(graph,K);
    REP(q,Q){
        int x,y;
        cin>>x>>y;
        x--;y--;
        int v=L.get(x,y);
        cout<<dist[x]+dist[y]<<"\n";
    }
}
