#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long llt;

const int MAXN = 5000;
const llt Mod = 1000000007;

int N, len;
char str[MAXN+1];
llt dp[MAXN+1][MAXN+1];

void init()
{
    memset( dp, 0, sizeof dp );
    scanf( "%d\n", &N );
    scanf( "%s", str );
    len = strlen( str );
}

llt fast_pow( llt low, int high )
{
    llt ans = 1;
    while ( high )
    {
        if ( high & 1 ) ans = ans * low % Mod;
        high >>= 1;
        low = low * low % Mod;
    }
    return ans;
}

llt Mod_inverse( llt x ) { return fast_pow( x, Mod - 2 ); }

void solve()
{
    dp[0][0] = 1;
    for ( int i = 1; i <= N; ++i )
    {
        dp[i][0] = ( dp[i - 1][1] + dp[i - 1][0] ) % Mod;
        dp[i][i] = dp[i - 1][i - 1] * 2 % Mod;
        for ( int j = 1; j < i; ++j )
            dp[i][j] = ( dp[i - 1][j - 1] * 2 + dp[i - 1][j + 1] ) % Mod;
    }
    llt ans = dp[N][len] * Mod_inverse( fast_pow( 2, len ) ) % Mod;
    printf( "%lld\n", ans );
}

int main()
{
    init();
    solve();
    return 0;
}