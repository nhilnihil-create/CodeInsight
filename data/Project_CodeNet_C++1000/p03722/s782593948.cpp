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
    for(int i=0;i<2*n;i++){
        for(auto e:edges){
            if(d[e.from]!=-INF&&d[e.to]<d[e.from]+e.cost){
                d[e.to]=min(d[e.from]+e.cost,INF);
                if(i>=n-1){
                    d[e.to]=INF;
                }
            }
        }
    }
    for(auto e:edges){
        if(d[e.from]!=-INF&&d[e.to]<d[e.from]+e.cost){
            d[e.to]=min(d[e.from]+e.cost,INF);
        }
    }
    if(d[n-1]==INF) cout<<"inf"<<endl;
    else cout<<d[n-1]<<endl;
}