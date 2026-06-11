#include<bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;i++)
using namespace std;
const int maxn=200500;
const int inf=1e9;
typedef long long ll;
const ll mm=1e9+7;
ll fac[4050000],inv[4050000];
int n,k;
ll f[2050][2050];
ll Pow(ll x,ll y){
    ll ans=1;
    while (y){
        if (y&1) ans=ans*x%mm;
        x=x*x%mm;
        y/=2;
    }
    return ans;
}
ll C(ll n,ll m){
    return fac[n]*inv[m]%mm*inv[n-m]%mm;
}
int main(){
    int N=4000000;
    fac[0]=1;
    rep(i,1,N) fac[i]=fac[i-1]*i%mm;
    inv[N]=Pow(fac[N],mm-2);
    for (int i=N;i>=1;i--) inv[i-1]=inv[i]*i%mm;
    //rep(i,1,10) printf("%lld %lld\n",fac[i],inv[i]);
    scanf("%d%d",&n,&k);
    f[0][0]=1;
    rep(i,1,n) rep(j,0,i){
        if (i-1>=j) f[i][j]=f[i-1][j];
        if (j) (f[i][j]+=C(n-i+(n-j+1)*(k-1)-1,k-2)*f[i][j-1]%mm*(n-j+1)%mm)%=mm;
    }
    if (k>1) printf("%lld\n",f[n][n]);
    else printf("%lld\n",f[n][0]);
    return 0;
}