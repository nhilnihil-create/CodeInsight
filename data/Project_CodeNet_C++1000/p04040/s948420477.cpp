#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n=200005;
const int mod=1e9+7;
ll Pow(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1)res=res*x%mod;
        y>>=1;
        x=x*x%mod;
    }
    return res;
}
int n,m,a,b;
ll fac[max_n],inv[max_n];
void init(int n){
    fac[0]=1;
    for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
    inv[n]=Pow(fac[n],mod-2);
    for(int i=n-1;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
}
ll C(int n,int m){
    if(n<m||m<0)return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
ll way(int n,int m){
    return C(n+m-2,n-1);
}
int main(){
    scanf("%d%d%d%d",&n,&m,&a,&b);
    init(n+m);
    ll ans=way(n,m);
    for(int i=1;i<=b;i++){
        ans-=way(n-a,i)*way(a,m-i+1)%mod;
    }
    ans=ans%mod+mod,ans%=mod;
    printf("%lld\n",ans);
    return 0;
}