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

int main()
{
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g.add_edge(a, b);
        g.add_edge(b, a);
    }
    int u = 0, v = 0;
    bool b[100005]{0};
    b[0] = true;
    vector<int> l, r;
    bool f = true;
    while(f){
        f = false;
        for(int w : g.g[u]){
            if(!b[w]){
                b[w] = true;
                l.push_back(w);
                u = w;
                f = true;
                break;
            }
        }
        for(int w : g.g[v]){
            if(!b[w]){
                b[w] = true;
                r.push_back(w);
                v = w;
                f = true;
                break;
            }
        }
    }
    cout << (int)l.size() + (int)r.size() + 1 << endl;
    reverse(l.begin(), l.end());
    for(int u : l) cout << u + 1 << " ";
    cout << 1 << " ";
    for(int u : r) cout << u + 1 << " ";
    cout << endl;
}
