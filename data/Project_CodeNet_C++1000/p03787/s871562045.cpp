#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

struct Graph
{
    int n;
    vector<vector<int>> g;
    
    Graph(int n) : n(n){
        g.resize(n);
    }
    
    void init(int n_){
        n = n_;
        g.resize(n_);
    }
    
    void add_edge(int from, int to){
        g[from].push_back(to);
    }
};

struct SCCD    //StronglyConnectedComponentsDecomposition
{
    vector<vector<int>> g;
    vector<vector<int>> rg;
    int n;
    vector<bool> used;
    vector<int> cmp;
    vector<int> vs;
    
    SCCD(Graph &g_){
        n = g_.n;
        g.resize(n);
        rg.resize(n);
        for(int u = 0; u < n; u++) for(int v : g_.g[u]){
            g[u].push_back(v);
            rg[v].push_back(u);
        }
        used.resize(n);
        cmp.resize(n);
    }
    
    void dfs(int u){
        used[u] = true;
        for(int v : g[u]){
            if(!used[v]) dfs(v);
        }
        vs.push_back(u);
    }
    
    void rdfs(int u, int k){
        used[u] = true;
        cmp[u] = k;
        for(int v : rg[u]){
            if(!used[v]) rdfs(v, k);
        }
    }
    
    int decomposition(){
        fill(used.begin(), used.end(), false);
        for(int i = 0; i < n; i++){
            if(!used[i]) dfs(i);
        }
        fill(used.begin(), used.end(), false);
        int k = 0;
        for(int i = n - 1; i >= 0; i--){
            if(!used[vs[i]]){
                rdfs(vs[i], k);
                k++;
            }
        }
        return k;
    }
};

int b[100002];

bool BipartiteGraph(Graph &g, int i){
    queue<int> que;
    b[i] = 1;
    que.push(i);
    while(que.size()){
        int u = que.front();
        que.pop();
        for(int v : g.g[u]){
            if(b[u] == b[v]){
                return false;
            }
            if(b[v] == 0){
                b[v] = 3 - b[u];
                que.push(v);
            }
        }
    }
    return true;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    Graph g(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g.add_edge(u, v);
        g.add_edge(v, u);
    }
    SCCD scc(g);
    ll k = scc.decomposition();
    bool l[100002]{0};
    ll s[100002]{0};
    for(int i = 0; i < n; i++) s[scc.cmp[i]]++;
    ll t[3]{0};
    for(int i = 0; i < n; i++){
        if(l[scc.cmp[i]]) continue;
        l[scc.cmp[i]] = true;
        if(s[scc.cmp[i]] == 1) t[2]++;
        else if(BipartiteGraph(g, i)) t[1]++;
        else t[0]++;
    }
    ll ans = n * n - (n - t[2]) * (n - t[2]) + (k - t[2]) * (k - t[2]) + t[1] * t[1];
    cout << ans << endl;
}