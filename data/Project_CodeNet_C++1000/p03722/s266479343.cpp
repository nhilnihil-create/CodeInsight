#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll MOD = 1e9+7;
ll LLINF = 1LL << 60;
int INF = INT_MAX;

struct edge { int to; ll cost; };
using graph = vector<vector<edge>>;

// true -> 負の閉路を含む
bool bellman_ford(const graph &G, vector<ll> &dist, int s){
    dist[s] = 0;
    rep(i,0,G.size()){
        rep(v,0,G.size()){
            rep(k,0,G[v].size()){
                edge e = G[v][k];
                if(dist[v] != LLINF && dist[e.to] > dist[v] + e.cost){
                    dist[e.to] = dist[v] + e.cost;
                    if(i == G.size()-1 && e.to == G.size()-1) return true;
                }
            }
        }
    }
    return false;
}

int main(){
    int n; int m; cin >> n >> m;
    graph G(n);
    vector<ll> dist(n, LLINF);

    rep(i,0,m){
        int from, to;
        ll cost;
        cin >> from >> to >> cost;
        from--; to--; cost*=(-1);
        G[from].push_back({to, cost});
    }
    if(bellman_ford(G,dist,0)){
        cout<<"inf"<<endl;
    }else{
        cout<<dist[n-1]*(-1)<<endl;
    }

}