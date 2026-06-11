#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

int n,k;
int dp[2050][2050];

int fac[4000050],inv[4000050];
int ksm(int x,int y){
    int z = 1;
    while(y){
        if(y & 1) z = z * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return z;
}
int C(int n,int m){
    if(n < m || m < 0) return 0;
    if(n == m || m == 0) return 1;
    return (fac[n] * inv[m] % mod) * inv[n - m] % mod;
}

signed main(){
    scanf("%lld%lld",&n,&k);
    
    fac[0] = 1;
    for(int i = 1; i <= 4000000; ++ i) fac[i] = fac[i - 1] * i % mod;
    inv[4000000] = ksm(fac[4000000],mod - 2);
    for(int i = 3999999; i >= 0; -- i) inv[i] = inv[i + 1] * (i + 1) % mod;
    
    if(k == 1) { puts("1"); return 0; } 
    
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++ i){
        dp[i][0] = 1;
        for(int j = 1; j <= i; ++ j){
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] * C(n * k - i - (j - 1) * (k - 1) - 1, k - 2) % mod * (n - j + 1) % mod ) % mod; 
        }
    }
    
    printf("%lld\n",dp[n][n]);
    return 0;
}