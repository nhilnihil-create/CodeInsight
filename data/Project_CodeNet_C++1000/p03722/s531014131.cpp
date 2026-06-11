#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e15;

struct edge{
    int from, to;
    long long int cost;
};

int V,E;// number of (vertices, edges)
vector<edge> e;
vector<long long int> d;// shortest distances
vector<bool> negative;

void shortest_path(int s){// s = starting point
    // initialize (INF)
    for(int i=0; i<V; i++){
        d[i] = INF;
    }
    d[s] = 0LL;

    // search (rather naive)
    for(int i=0; i<V; i++){
        bool update = false;// flag
        for(int j=0; j<E; j++){
            if(d[e[j].from] != INF 
            && d[e[j].to] > d[e[j].from] + e[j].cost){
               d[e[j].to] = d[e[j].from] + e[j].cost;// update minimum cost
               update = true;
               if(i == V-1) negative[e[j].to] = true;
            }
            if(negative[e[j].from] == true) negative[e[j].to] = true;
        }
        if(update == false) break;// no updates anymore
    }
}

int main(){
    int s = 0;
    cin >> V >> E;
    d.resize(V);
    e.resize(E);
    negative.resize(V);

    for (int i=0; i<E; i++){
        cin >> e[i].from >> e[i].to >> e[i].cost;
        e[i].from -= 1;
        e[i].to -= 1;
        e[i].cost = -e[i].cost;
    }
    shortest_path(s);// starting from s
    if(negative[V-1] == true)  cout << "inf" << endl;
    if(negative[V-1] == false) cout << -d[V-1] << endl;
    return 0;
}