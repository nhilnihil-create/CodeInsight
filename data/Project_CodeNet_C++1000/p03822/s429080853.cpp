#include <algorithm>
#include <iostream>
#include <vector>
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

int dfs(Graph &g, int u){
    int k = g.g[u].size();
    vector<int> d(k);
    for(int i = 0; i < k; i++){
        int v = g.g[u][i];
        d[i] = dfs(g, v) + 1;
    }
    sort(d.begin(), d.end(), greater<int>());
    int res = 0;
    for(int i = 0; i < k; i++) res = max(res, d[i] + i);
    return res;
}

int main()
{
    int n;
    cin >> n;
    Graph g(n);
    for(int i = 1; i < n; i++){
        int a;
        cin >> a;
        a--;
        g.add_edge(a, i);
    }
    cout << dfs(g, 0) << endl;
}
