#include <bits/stdc++.h>
typedef long long ll;
static const ll INF = 100000000000000;
using namespace std;

int n,m; 
struct edge{
    int to;
    int from;
    ll cost;
};

vector<edge> g;

int main(){
    cin>>n>>m;
    ll ans = 0;
    ll d[1100];

    for(int i=0; i<m; i++){
        struct edge add;
        cin>>add.from;
        add.from--;
        cin>>add.to;
        add.to--;
        cin>>add.cost;
        add.cost *=(-1);
        g.push_back(add);
    }

    for(int i=0; i<1100; i++){
        d[i] = INF;
    }

    d[0] = 0;

    ll comp;
    
    for(int j=0; j<n-1; j++){
        for(int i=0; i<m; i++){
            d[g[i].to] = min(d[g[i].to],d[g[i].from]+g[i].cost);
        }
    }

    comp = d[n-1];

    for(int i=0; i<m; i++){
        if(d[g[i].to] > d[g[i].from]+g[i].cost){
            d[g[i].to] = min(d[g[i].to],d[g[i].from]+g[i].cost);
        }
    }


    if(comp != d[n-1]) cout<<"inf"<<endl;
    else cout<<(-1)*d[n-1]<<endl;

    return 0;
}