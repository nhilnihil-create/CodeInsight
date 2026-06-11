#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

const int INF = 1<<29;
using Edge = P;
using Graph = vector<vector<Edge>>;

Graph G;
set<P> use;

vector<ll> Dijkstra(int s){
    vector<ll> dist((int)G.size(), INF);
    vector<vector<int>> prev((int)G.size());
    dist[s] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push({0,s});
    while(!que.empty()){
        auto cur = que.top(); que.pop();
        int cur_dist = cur.first;
        int v = cur.second;
        //if(cur_dist > dist[v]) continue;
        for(auto e : G[v]){
            if(dist[e.first] > dist[v] + e.second){
                dist[e.first] = dist[v] + e.second;
                que.push({dist[e.first], e.first});
                prev[e.first].clear();
                prev[e.first].push_back(v);
            }else if(dist[e.first] == dist[v] + e.second){
                prev[e.first].push_back(v);
            }
        }
    }
    for(int v = 0; v < (int)G.size(); ++v){
        for(auto u : prev[v]){
            use.insert(make_pair(min(u, v), max(u, v)));
        }
    }
    return dist;
}


int main(){
    int n, m; cin >> n >> m;
    G.resize(n);
    rep(i,m){
        int a, b, c; cin >> a >> b >> c;
        --a, --b;
        G[a].push_back(P(b,c));
        G[b].push_back(P(a,c));
    }
    for(int v = 0; v < n; v++) Dijkstra(v);
    cout << m - (int)use.size() << endl;
}