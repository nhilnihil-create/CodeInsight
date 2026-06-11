#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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

int dfs(Tree &t, int u){
    int res = 0;
    for(int v : t.t[u]){
        res ^= dfs(t, v) + 1;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    Graph g(n);
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        g.add_edge(x, y);
        g.add_edge(y, x);
    }
    Tree t(g, 0);
    if(dfs(t, 0) != 0) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}