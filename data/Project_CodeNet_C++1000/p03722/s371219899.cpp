#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1001001001001001001;
const ll mod = 1000000007;
const int MAX = 1000100;
// to means the destination and cost is the weight of an edge
struct Edge{ll from, to, cost;};

struct graph{
    ll num;
    vector<Edge> edges;
    vector<ll> d;
    // constructor for initialization
    graph(ll n) : num(n), d(n){}
    // assembling a graph whose edge is coming from s to t
    void add_edge(ll s, ll t, ll cost){
        Edge e;
        e.from = s;
        e.to = t;
        e.cost = cost;
        edges.push_back(e);
    }    
    // Bellman-Ford algorithm
    // O(|V||E|)
    // you can use this even when a graph contains a negative weighted path
    void Bellman_Ford(ll s){
        for(int i = 0; i < num; i++){
            d[i] = INF;
        }
        bool ok = true;
        d[s] = 0;
        for(int i = 0; i < num; i++){
            for(int j = 0; j < edges.size(); j++){
                Edge e = edges[j];
                if(d[e.to] > d[e.from] + e.cost){
                    d[e.to] = d[e.from] + e.cost;
                    if(i == num - 1 && e.to == num - 1){
                        cout << "inf" << endl;
                        ok = false;
                        break;
                    }
                }
            }
        }
        if(ok) cout << -d[num - 1] << endl;
    }
};

int main(){
    int n, m; cin >> n >> m;
    graph G(n);
    for(int i = 0; i < m; i++){
        ll a, b, c; cin >> a >> b >> c;
        --a; --b;
        G.add_edge(a, b, -c);
    }
    G.Bellman_Ford(0);
}