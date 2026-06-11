#include <bits/stdc++.h>
#include <cmath>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INF = 1e18;
#define foreach(ix,a) for(auto& (ix) : (a)) 
vector<vector<pair<ll,ll>>> edge(110000);
ll seen[110000];
void dfs(ll i,ll co){    
    for(pair<ll,ll> v : edge[i]){
        ll p=v.first,dis=v.second;
        if(seen[p]!=-1)continue;
        seen[p]=(co+dis);
        dfs(p,seen[p]);
    }
}
int main(){
    int n;
    cin>>n;
    rep(i,n)seen[i]=-1;
    rep(i,n-1){
        ll u,v,w;cin>>u>>v>>w;u--;v--;
        edge[u].push_back({v,w});
        edge[v].push_back({u,w});
    }
    int q,k;
    cin>>q>>k;
    k--;
    seen[k]=0;
    dfs(k,seen[k]);
    rep(i,q){
        int a,b;
        cin>>a>>b;
        a--;b--;
        cout<<seen[a]+seen[b]<<endl;
    }

}