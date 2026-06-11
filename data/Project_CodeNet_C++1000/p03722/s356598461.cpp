#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1LL<<60;
struct edge {
    ll from;
    ll to;
    ll cost;
};
int main(void){
    ll n,m;
    ll d[1000];
    vector<edge> edges;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        struct edge add;
        cin>>add.from>>add.to>>add.cost;
        add.from--,add.to--;
        edges.push_back(add);
    }
    fill(d,d+n,-INF);
    d[0]=0;
    bool negative_cycle=false;
    for(int i=0;i<n-1;i++){
        for(auto e:edges){
            if(d[e.from]!=-INF&&d[e.to]<d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;
            }
        }
    }
    ll a=d[n-1];
    for(int i=0;i<n-1;i++){
        for(auto e:edges){
            if(d[e.from]!=-INF&&d[e.to]<d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;
            }
        }
    }
    if(a!=d[n-1]) cout<<"inf"<<endl;
    else cout<<d[n-1]<<endl;
}