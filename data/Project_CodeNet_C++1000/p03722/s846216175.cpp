#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef pair<int,int> P;
typedef long long ll;
const int INF = 1001001001;
const ll INFL = 1e17;
const int MOD = 1e9+7;

struct edge{ll from,to,cost;};
vector<bool> negative(1010,false);

bool Bellman_Ford(int s, int V, vector<ll>& dist, vector<edge>& G){
    fill(dist.begin(),dist.end(),INFL);
    dist[s] = 0;
    for(int loop = 0; loop < V*2; loop++){
        bool update = false;
        for(int i=0; i<int(G.size()); i++){
            edge e = G[i];
            if(dist[e.from] != INFL && dist[e.to] > dist[e.from] + e.cost){
                dist[e.to] = dist[e.from] + e.cost;
                update = true;
                if(loop >= V){
                    negative[e.to] = true;
                }
                if(loop == 2*V-1){
                    return true;
                }
            } 
        }
        if(!update) break;
    }
    return false;
}

int main(){
    int V,E;
    cin >> V >> E;
    vector<ll> dist(V);
    vector<edge> G;
    rep(i,E){
        int a,b,c;
        cin >> a >> b >> c;
        --a; --b; c = -c;
        G.push_back(edge{a,b,c});
    }
    if(Bellman_Ford(0,V,dist,G) && negative[V-1]){
        cout << "inf" << endl;
    }else{
        cout << -dist[V-1] << endl;
    }

    return 0;
}