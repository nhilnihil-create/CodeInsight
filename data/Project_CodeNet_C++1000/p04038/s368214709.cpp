#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod (long long)(1e9+7)
int dp[2001][2001];
int fac[2001*2001],ifac[2001*2001];
int fastpow(int x,int y){
    int res=1;
    while(y){
        if(y&1)res=res*x%mod;
        y>>=1;
        x=x*x%mod;
    }
    return res;
}
void init(int top){
    fac[0]=1;
    for(int i=1;i<=top;++i)fac[i]=(fac[i-1]*i)%mod;
    ifac[0]=ifac[1]=1;
    ifac[top]=fastpow(fac[top],mod-2);
    for(int i=top-1;i>1;--i)ifac[i]=(ifac[i+1]*(i+1))%mod;
}
int C(int n,int m){
    return ((fac[n]*ifac[m])%mod*ifac[n-m])%mod;
}
signed main(){
    int n,k;
    scanf("%d%d",&n,&k);
    if(k==1){
        puts("1");
        exit(0);
    }
    init(n*k);
    k--;
    dp[0][0]=1;
    for(int i=0;i<=n;++i){
        for(int j=i;j<=n;++j){
            if(i)dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
            if(j)dp[i][j]=(dp[i][j]+(dp[i][j-1]*C(i+(j-1)*k+k-1,k-1))%mod)%mod;
        }
    }
    printf("%lld\n",(dp[n][n]*fac[n])%mod);
}
