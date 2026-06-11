#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int MAX_V = 1001;
const int MAX_E = 2001;
const ll INF = 1e18;

struct edge{
    int from, to;
    ll cost;
};

edge es[MAX_E];

ll d[MAX_V];
int V, E;
bool update;
bool negative[MAX_V];

void bellmanford(int s){
    for(int i = 1; i <= V; i++) d[i] = INF;
    d[s] = 0;
    for(int j = 0; j < V-1; j++){
        update = false;
        for(int i = 0; i < E; i++){
            edge e = es[i];
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if(!update) break;
    }
    for(int j = 0; j < V; j++){
        for(int i = 0; i < E; i++){
            edge e = es[i];
            if(d[e.from] == INF) continue;
            if(d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                negative[e.to] = true;
            }
            if(negative[e.from]) negative[e.to] = true;
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        int from, to;
        ll cost;
        cin >> from >> to >> cost;
        es[i] = edge{from, to, -cost};
    }
    bellmanford(1);
    if(negative[V]) cout << "inf" << endl;
    else cout << -d[V] << endl;
    return 0;
}