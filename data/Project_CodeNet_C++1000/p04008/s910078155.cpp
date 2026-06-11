#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;

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

int main()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    Graph g(n);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        a--;
        if(i == 0){
            if(a != 0) ans++;
        }
        else{
            g.add_edge(i, a);
            g.add_edge(a, i);
        }
    }
    Tree t(g, 0);
    P p[100005];
    bool b[100005]{0};
    for(int i = 0; i < n; i++) p[i] = P(t.dpt[i], i);
    sort(p, p + n, greater<P>());
    for(int i = 0; i < n; i++){
        int u = p[i].second;
        if(b[u]) continue;
        for(int i = 0; i < k - 1; i++){
            if(u == 0) break;
            u = t.par[u];
        }
        if(u != 0 && t.par[u] != 0) ans++;
        queue<int> que;
        que.push(u);
        b[u] = true;
        while(que.size()){
            int v = que.front();
            que.pop();
            for(int w : t.t[v]){
                if(!b[w]){
                    b[w] = true;
                    que.push(w);
                }
            }
        }
    }
    cout << ans << endl;
}