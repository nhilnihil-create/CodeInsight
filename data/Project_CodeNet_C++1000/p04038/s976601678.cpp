#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
long long n,k;
long long dp[2010][2010];
long long fac[4000010],inv[4000010];
long long fpm(long long a,long long b){
    long long res = 1;
    while(b){
        if (b&1){
            res = res*a%mod;
            b--;
        }
        a = a*a%mod;
        b>>=1;
    }
    return res;
}
long long C(long long n,long long m){
    if (n<m){
        return 0;
    }
    return fac[n]*inv[n-m]%mod*inv[m]%mod;
}
int main () {
    scanf("%lld%lld",&n,&k);
    if (k==1){
        printf("1");
        return 0;
    }
    fac[0] = 1;
    inv[0] = 1;
    for (register int i = 1; i <= 4000000; i++){
        fac[i] = fac[i-1]*i%mod;
        inv[i] = fpm(fac[i],mod-2)%mod;
    }
    dp[0][0] = 1;
    for (register int i = 1; i <= n; i++){
        for (register int j = 0; j <= i; j++){
            dp[i][j] = dp[i-1][j];
            if (j==0){
                continue;
            }
            dp[i][j] += dp[i][j-1]*(n-j+1)%mod*C(n-i+(n-j+1)*(k-1)-1,k-2)%mod;
            dp[i][j] %= mod;
        }
    }
    printf("%lld",dp[n][n]);
    return 0;
}