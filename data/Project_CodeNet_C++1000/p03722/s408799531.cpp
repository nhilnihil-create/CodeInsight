#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(ll i=0;i<n;i++)
const ll INF=1e15;
const ll MOD=1000000007;

struct edge{
    ll from;
    ll to;
    ll cost;
};
int main(){
    ll N,M;cin>>N>>M;
    vector<edge> edges;
    rep(i,M){
        edge add;
        cin>>add.from>>add.to>>add.cost;
        add.from--;add.to--;add.cost*=-1;
        edges.push_back(add);
    }
    ll dist[N];
    fill(dist+1,dist+N,INF);
    dist[0]=0;
    rep(i,N){
        rep(j,edges.size()){
            ll a=edges.at(j).from,b=edges.at(j).to,c=edges.at(j).cost;
            if(dist[a]+c<dist[b])dist[b]=dist[a]+c;
        }
    }
    ll ans=-dist[N-1];
    bool negative[N];
    rep(i,N)negative[i]=false;
    rep(i,N){
        rep(j,edges.size()){
            ll a=edges.at(j).from,b=edges.at(j).to,c=edges.at(j).cost;
            if(dist[a]==INF)continue;
            if(dist[a]+c<dist[b]){
                dist[b]=dist[a]+c;
                negative[b]=true;
            }
            if(negative[a]==true)negative[b]=true;
        }
    }
    if(negative[N-1])cout<<"inf"<<endl;
    else cout<<ans<<endl;
    return 0;
}