/// You just can't beat the person who never gives up
/// ICPC next year

///#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
///#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
using namespace std ;
const int N = 3e5+5 ,mod = 1e9+7 ;

int h ,w ,a ,b ,ans ,dp[N] ,fac[N] ,inv[N] ;
int pwr(int b,int p){
    int res = 1;
    while(p){
        if(p%2) res = 1ll*res*b%mod ;
        b = 1ll*b*b%mod;
        p/=2;
    }
    return res;
}
int ways(int x0,int y0,int x1,int y1){
    int rit = x1 - x0 ;
    int down = y1 - y0 ;
    return 1ll * fac[rit+down] * inv[rit] %mod * inv[down] %mod ;
}
int main(){
    fac[0] = inv[0] = 1 ;
    for(int i=1;i<N;++i){
        fac[i]=(1ll*fac[i-1]*i)%mod;
        inv[i]=pwr(fac[i],mod-2);
    }
    cin >> h >> w >> a >> b ;
    for(int i=h-a;i>=1;--i){
        dp[i] = (0ll + ways(i,b+1,h,w) /*+ dp[i+1]*/)%mod ;
        ans = (ans + 1ll * ways(1,1,i,b) * dp[i] %mod)%mod ;
    }
    cout << ans ;
    return 0;
}
