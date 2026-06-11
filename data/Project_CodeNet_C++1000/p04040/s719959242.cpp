#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
ll mod=1e9+7,A[200001];
ll inv(ll a){
    ll n=mod-2,ans=1;
    while(n>0){
        if(n%2) ans=ans*a%mod;
        n=n/2;
        a=a*a%mod;
    }
    return ans;
}
ll nCr(ll a,ll b){
    ll ans=A[a];
    ans=ans*inv(A[b])%mod;
    ans=ans*inv(A[a-b])%mod;
    return ans;
}
int main(){
    ll h,w,a,b,ans=0;
    cin>>h>>w>>a>>b;
    A[0]=1;
    rep(i,200000) A[i+1]=A[i]*(i+1)%mod;
    rep(i,h-a) ans=(ans+nCr(i+b-1,i)*nCr(h+w-i-b-2,w-b-1)%mod)%mod;
    cout<<ans;
}