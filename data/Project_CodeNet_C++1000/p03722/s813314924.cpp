#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n,m;cin>>n>>m;
    ll a[m],b[m],c[m];for(ll i=0;i<m;i++)cin>>a[i]>>b[i]>>c[i];
    for(ll i=0;i<m;i++)a[i]-=1,b[i]-=1,c[i]*=-1;
    vector<ll> dist(n,LLONG_MAX);
    dist[0]=0;
    for(ll t=0;t<n-1;t++){
        for(ll i=0;i<m;i++){
            if(dist[a[i]]==LLONG_MAX)continue;
            if(dist[b[i]]>dist[a[i]]+c[i])dist[b[i]]=dist[a[i]]+c[i];
        }
    }
    vector<bool> neg(n,0);
    for(ll t=0;t<n;t++){
        for(ll i=0;i<m;i++){
            if(dist[a[i]]==LLONG_MAX)continue;
            if(dist[b[i]]>dist[a[i]]+c[i])dist[b[i]]=dist[a[i]]+c[i],neg[b[i]]=1;
            if(neg[a[i]])neg[b[i]]=1;
        }
    }
    if(neg[n-1])cout<<"inf";
    else cout<<-1*dist[n-1];
}
