#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int quickpow(int x,int y){
    int answ = 1,res = x;
    while(y){
        if(y%2) answ = answ * res % mod;
        y /= 2,res = res * res % mod;
    }
    return answ;
}
int n,m,x,y;
int ans = 0;
signed main(){
    scanf("%lld%lld%lld%lld",&n,&m,&x,&y);
    int res = 1,res2 = 1,res3 = 1,res4 = 1;
    for(int i = 1;i<y;i++) res = res * i % mod;
    res = quickpow(res,mod-2);
    for(int i = 1;i<m-y;i++) res2 = res2 * i % mod;
    res2 = quickpow(res2,mod-2);
    for(int i = 1;i<y;i++) res3 = res3 * i % mod;
    for(int i = n+m-y-2;i>=n;i--) res4 = res4 * i % mod; 
    int res5 = 0;
    ans = ( ans + res * res2 % mod * res3 % mod * res4 % mod ) % mod;
    for(int i = 2;i<=n-x;i++){
        res3 = res3 * quickpow(i-1,mod-2) % mod * (y+i-2) % mod;
        res4 = res4 * quickpow(n+m-y-i,mod-2) % mod * (n-i+1) % mod;
        ans =  ( ans + res * res2 % mod * res3 % mod * res4 % mod ) % mod;
    }
    printf("%lld",ans);
    return 0;
}