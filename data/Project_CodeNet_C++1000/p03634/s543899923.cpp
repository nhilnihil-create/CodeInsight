#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


struct State{
    int at;
    ll cost;
    State(int a, ll c) : at(a), cost(c){}
    bool operator>(const State& s) const{
        return cost > s.cost;
    }
};

struct Edge{
    int to;
    ll cost;
    Edge(int t, ll c) : to(t), cost(c){}
};

using Graph = vector<vector<Edge> >;
const ll INF = 1e15;

void dijkstra(int s, const Graph& G, vector<ll>& minc){
    minc.assign(G.size(), INF);
    priority_queue<State, vector<State>, greater<State> > pq;
    pq.emplace(s, 0);
    minc[s] = 0;
    while(!pq.empty()){
        State cur = pq.top();
        pq.pop();
        if(minc[cur.at] < cur.cost) continue;
        for(const Edge& e : G[cur.at]){
            ll cost = cur.cost + e.cost;
            if(minc[e.to] <= cost) continue;
            minc[e.to] = cost;
            pq.emplace(e.to, cost);
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    Graph G(n);
    rep(i,n-1){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        --a; --b;
        G[a].push_back(Edge(b, c));
        G[b].push_back(Edge(a, c));
    }
    int q, k;
    cin >> q >> k;
    --k;
    vector<ll> minc(n, INF);
    dijkstra(k, G, minc);
    rep(i,q){
        int x, y;
        cin >> x >> y;
        --x; --y;
        cout << minc[x] + minc[y] << endl;
    }
    return 0;
}