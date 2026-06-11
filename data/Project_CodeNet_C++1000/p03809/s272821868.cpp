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

struct Tree	//create tree(directed) from graph(undirected)
{
    int n;
    int root;
    vector<vector<int>> t;
    vector<int> par;
    vector<int> dpt;
    
    void init(Graph &g, int root_){
        n = g.n;
        root = root_;
        t.resize(n);
        par.resize(n);
        dpt.resize(n);
        fill(dpt.begin(), dpt.end(), -1);
        queue<int> que;
        par[root] = -1;
        dpt[root] = 0;
        que.push(root);
        while(que.size()){
            int pa = que.front();
            que.pop();
            for(int ch : g.g[pa]){
                if(dpt[ch] == -1){
                    t[pa].push_back(ch);
                    par[ch] = pa;
                    dpt[ch] = dpt[pa] + 1;
                    que.push(ch);
                }
            }
        }
    }

    Tree(){}
    
    Tree(Graph &g, int root_){
        init(g, root_);
    }
};

Tree t;
ll a[100002];
ll memo[100002];

ll dfs(int u){
    if(memo[u]) return memo[u];
    if((int)t.t[u].size() == 0) return memo[u] = a[u];
    ll s = 0, l = 0;
    for(int v : t.t[u]){
        ll c = dfs(v);
        if(c == -1) return memo[u] = -1;
        s += c;
        l = max(l, c);
    }
    if(a[u] * 2 >= s && a[u] >= l && a[u] <= s) return memo[u] = a[u] * 2 - s;
    return memo[u] = -1;
}

int main()
{
    int n;
    cin >> n;
    Graph g(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g.add_edge(u, v);
        g.add_edge(v, u);
    }
    t.init(g, 0);
    if(((int)t.t[0].size() == 1 && dfs(0) == a[0]) || ((int)t.t[0].size() != 1 && dfs(0) == 0)) cout << "YES" << endl;
    else cout << "NO" << endl;
}