#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n,m,r;cin>>n>>m>>r;
    vector<ll> a(r);for(ll i=0;i<r;i++)cin>>a[i],a[i]-=1;
    ll dist[n][n];
    for(ll i=0;i<n;i++)for(ll j=0;j<n;j++)dist[i][j]=1e12;
    for(ll i=0;i<n;i++)dist[i][i]=0;
    for(ll i=0;i<m;i++){
        ll u,v,w;cin>>u>>v>>w;
        dist[u-1][v-1]=dist[v-1][u-1]=w;
    }
    for(ll k=0;k<n;k++)for(ll i=0;i<n;i++)for(ll j=0;j<n;j++)dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
    ll ans=1e12;
    sort(a.begin(),a.end());
    do{
        ll cur=0;
        for(ll i=1;i<r;i++)cur+=dist[a[i-1]][a[i]];
        ans=min(ans,cur);
    }while(next_permutation(a.begin(),a.end()));
    cout<<ans;
}
