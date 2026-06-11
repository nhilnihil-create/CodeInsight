#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pb push_back
#define ff first
#define ss second
using namespace std;
vector<pll>vec[100005];
ll dist[100005];
void dfs(ll node,ll parent,ll value)
{
    dist[node]=value;
    for(auto i:vec[node]){
        if(i.ff==parent)continue;
        dfs(i.ff,node,value+i.ss);
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,a,b,c,q,k;
    cin>>n;
    for(int i=1;i<=n-1;i++){
        cin>>a>>b>>c;
        vec[a].pb({b,c});
        vec[b].pb({a,c});
    }
    cin>>q>>k;
    dfs(k,-1,0);
    while(q--){
        cin>>a>>b;
        cout<<dist[a]+dist[b]<<endl;
    }
    return 0;
}
