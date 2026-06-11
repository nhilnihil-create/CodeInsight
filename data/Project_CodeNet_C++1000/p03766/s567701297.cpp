#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
typedef long long LL;
LL dp[1000005];
int main(){
    int n;
    scanf("%d", &n);

    LL res1 = (n-1)*1ll*n%mod;
    LL res2 = 0;
    dp[1] = n;
    for(int i=2;i<=n;i++){
        if(i >= 4){
            res1 = (res1 - n + mod)%mod;
            res2 = (res2 + dp[i-3] + n-1)%mod;
        }
        dp[i] = (dp[i-1] + res1 + res2)%mod;
    }
    printf("%lld\n", dp[n]);
}