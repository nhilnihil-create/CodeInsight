#include <bits/stdc++.h>
using namespace std;

const int DIM = 5e3 + 5;
const int MOD = 1e9 + 7;

string str;
int dp[2][DIM];

int main( void ) {
    
    int n, k;
    cin >> n >> str;
    k = (int) str.length();
    
    dp[0][0] = 1;
    for( int i = 1; i <= n; i ++ )
        for( int j = 0; j <= n; j ++ )
            dp[i & 1][j] = ( dp[(i - 1) & 1][j + 1] * 2LL +
                             dp[(i - 1) & 1][max( 0, j - 1 )] ) % MOD;
    
    cout << dp[n & 1][k] << endl;
    return 0;
}