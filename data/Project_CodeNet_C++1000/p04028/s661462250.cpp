#include <bits/stdc++.h>

using namespace std;

//#define FILE_IO

const int mod = 1e9 + 7;

int N, M;
int dp[5005][5005];
char s[5005];

int power(int x, int y)
{
    int p = x, r = 1;
    while(y)
    {
        if(y & 1)
            r = (1LL * r * p) % mod;
        p = (1LL * p * p) % mod;
        y >>= 1;
    }
    return r;
}

int main()
{
    #ifdef FILE_IO
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    scanf("%d\n", &N);
    scanf("%s", s);
    M = strlen(s);

    dp[0][0] = 1;
    /// dp[i][j] - i moves, j characters
    for(int i = 1; i <= N; i++)
    {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        for(int j = 1; j <= N; j++)
            dp[i][j] = ( (2 * dp[i - 1][j - 1]) % mod + dp[i - 1][j + 1] ) % mod;
    }

    int ans = dp[N][M];
    int p2 = power(2, M);
    int invp2 = power(p2, mod - 2);
    ans = (1LL * ans * invp2) % mod;
    printf("%d\n", ans);

    return 0;
}
