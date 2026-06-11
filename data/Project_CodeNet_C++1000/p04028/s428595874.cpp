#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n, k;
int dp[5005][5005];
char s[5005];

inline int lgput(int x, int p){
    int ans = 1, aux = x;
    for(int i = 1; i <= p ; i = i << 1){
        if(i & p) ans = (1LL * ans * aux) % MOD;
        aux = (1LL * aux * aux) % MOD;
    }
    return ans;
}

int main()
{
    scanf("%d", &k);
    scanf("%s", s);
    n = strlen(s);

    dp[0][0] = 1;
    for(int i = 1; i <= k ; ++i){
        for(int j = 0; j <= k ; ++j){
            if(j > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * 2LL) % MOD;
            if(j == 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
        }
    }

    int i2 = lgput(2, MOD - 2);
    int ans = dp[k][n];
    for(int i = 1; i <= n ; ++i)
        ans = (1LL * ans * i2) % MOD;

    printf("%d", ans);

    return 0;
}










