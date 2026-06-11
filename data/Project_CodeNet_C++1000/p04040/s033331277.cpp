#include<bits/stdc++.h>
#define P pair<int,int>
using namespace std;
typedef long long ll;
const int maxx=1e6+10;
const ll mod=1e9+7;
ll f[maxx],inv[maxx];
ll fpow(ll x,ll n){
    ll res=1;
    while(n){
        if(n&1) res=res*x%mod;
        x=x*x%mod;
        n >>=1;
    }
    return res;
}
void init(){
    f[0]=inv[0]=1;
    for(int i=1;i<=1000000;i++) f[i]=f[i-1]*i%mod;
    inv[1000000]=fpow(f[1000000],mod-2);
    for(int i=1000000-1;i;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
ll C(int n,int m){
    return f[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
    init();
    int n,m,a,b; cin>>n>>m>>a>>b;
    a=n-a+1;
    ll ans=C(n+m-2,n-1);
    for(int i=n;i>=a;i--){
        ans=(ans-C(b+i-2,b-1)*C((n-i+1)+m-b-2,m-b-1)%mod+mod)%mod;
    }
    cout<<ans<<endl;
}
