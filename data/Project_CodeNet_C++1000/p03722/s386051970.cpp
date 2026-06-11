#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 1001;
const int MAX_E = 2001;
const long long INF = 1e18;

struct edge{
    int from, to;
    long long cost;
};

edge es[MAX_E];

long long d[MAX_V];
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
        long long cost;
        cin >> from >> to >> cost;
        es[i] = edge{from, to, -cost};
    }
    bellmanford(1);
    if(negative[V]) cout << "inf" << endl;
    else cout << -d[V] << endl;
    return 0;
}