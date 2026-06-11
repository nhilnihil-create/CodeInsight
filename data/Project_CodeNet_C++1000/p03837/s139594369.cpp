#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1005 , inf=1e17;
ll a[N],b[N],c[N],dist[105][105];
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n,m,ans=0;cin>>n>>m;
    for(ll i=0;i<m;i++)cin>>a[i]>>b[i]>>c[i],a[i]-=1,b[i]-=1;
    for(ll i=0;i<n;i++)for(ll j=0;j<n;j++)dist[i][j]=(i==j?0:inf);
    for(ll i=0;i<m;i++)dist[a[i]][b[i]]=min(dist[a[i]][b[i]],c[i]);
    for(ll i=0;i<m;i++)dist[b[i]][a[i]]=min(dist[b[i]][a[i]],c[i]);
    for(ll k=0;k<n;k++)for(ll i=0;i<n;i++)for(ll j=0;j<n;j++)dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    for(ll i=0,chk=0;i<m;i++,chk=0){
        for(ll j=0;j<n;j++)if(dist[j][a[i]]+c[i]==dist[j][b[i]])chk=1;
        ans+=chk;
    }
    cout<<m-ans;
}
