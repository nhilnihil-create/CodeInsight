#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

#define MAX_E 2000
#define MAX_V 1000

ll INF = 1000000000000;
//ベルマンフォード法
//計算量O(VE) 頂点数＊辺数
struct edge{ll from, to, cost;};
edge es[MAX_E];
ll d[MAX_V];
ll V, E;

bool shortest_path(ll s){
    for(ll i = 0; i < V; i++) d[i] = INF;
    d[s] = 0;
    for(ll i = 0; i < 2 * V; i++){
        for(ll j = 0; j < E; j++){
            edge e = es[j];
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                if(i >= V - 1 && e.to == V - 1) return true;
            }
        }
    }
    return false;
}

int main(void){
    cin >> V >> E;
    rep(i, 0, E){
        cin >> es[i].from >> es[i].to >> es[i].cost;
        es[i].from--;
        es[i].to--;
        es[i].cost = -es[i].cost;
    }

    if(shortest_path(0)){
        cout << "inf" << endl;
    }else{
        cout << -d[V - 1] << endl;
    }

    return 0;
}
