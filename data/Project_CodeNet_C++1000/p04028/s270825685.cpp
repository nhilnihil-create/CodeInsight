#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int n,m,dp[5005][5005];
char s[5005];
inline int ksm(int x,int n) {
    int ret=1;
    while (n) {
        if (n&1) ret=1ll*ret*x%mod;
        n>>=1;
        x=1ll*x*x%mod;
    }
    return ret;
}
int main()
{
    scanf("%d%s",&n,s+1);
    m=strlen(s+1);
    dp[0][0]=1;
    for (int i=1;i<=n;++i) {
        dp[i][0]=(dp[i][0]+dp[i-1][0])%mod;
        for (int j=0;j<=i;++j) {
            if (j) dp[i][j]=(dp[i][j]+2*dp[i-1][j-1]%mod)%mod;
            dp[i][j]=(dp[i][j]+dp[i-1][j+1])%mod;
        }
    }
    int res=1ll*dp[n][m]*ksm(ksm(2,m),mod-2)%mod;
    printf("%d\n",res);
    return 0;
}
