#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int main(){
    ll n,m,x[200001],y[200001],ansx=0,ansy=0,mod=1e9+7;
    cin>>n>>m;
    rep(i,n) cin>>x[i];
    rep(i,m) cin>>y[i];
    rep(i,n-1) ansx=(ansx+(i+1)*(n-i-1)%mod*(x[i+1]-x[i])%mod)%mod;
    rep(i,m-1) ansy=(ansy+(i+1)*(m-i-1)%mod*(y[i+1]-y[i])%mod)%mod;
    cout<<ansx*ansy%mod;
}