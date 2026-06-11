#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> P;
struct edge{ int from,to,cost;};
edge es[2001];
ll d[1001],V,E,INF=1e18;
int find_negative_loop(){
    rep(i,V+1) d[i]=0;
    rep(i,2*V)rep(j,E){
        edge e=es[j];
        if(d[e.to]>d[e.from]+e.cost){
            d[e.to]=d[e.from]+e.cost;
            if(i>=V-1&&e.to==V-1) return 1;
        }
    }
    return 0;
}
int shortest_path(int s){
    rep(i,V+1) d[i]=INF;
    d[s]=0;
    rep(j,V-1){
        int x=0;
        rep(i,E){
            edge e=es[i];
            if(d[e.from]!=INF&&d[e.to]>d[e.from]+e.cost) d[e.to]=d[e.from]+e.cost,x=1;
        }
        if(!x) break;
    }
}
int main(){
    int a,b,c;
    cin>>V>>E;
    rep(i,E) cin>>a>>b>>c,es[i].from=a-1,es[i].to=b-1,es[i].cost=-c;
    if(find_negative_loop()) cout<<"inf";
    else{
        shortest_path(0);
        cout<<-d[V-1];
    }
}