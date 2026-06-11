#include<bits/stdc++.h>
using namespace std;
long long dp[5050][5050]; //i keystroke, j remain
int N;
const int MOD = 1e9+7;
const int MODINV = (MOD+1)/2;

char s[10101];
int main()
{
    scanf("%d%s", &N, s); int K = strlen(s);
     
    dp[0][0] = 1;
    for(int i=0; i<=N; ++i)
    {
        for(int j=0; j<=i; ++j)
        {
            dp[i][j] %= MOD;
            dp[i+1][max(j-1, 0)] += dp[i][j];
            dp[i+1][j+1] += 2*dp[i][j];
        }
    }
    long long ans = dp[N][K];
    for(int i=0; i<K; ++i) ans = (ans*MODINV)%MOD;
    printf("%lld\n", ans);
    return 0;
}