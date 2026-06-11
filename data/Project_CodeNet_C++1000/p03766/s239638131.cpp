#include <bits/stdc++.h>
using namespace std;

const int DIM = 1e6 + 5;
const int MOD = 1e9 + 7;

int dp[DIM], psm[DIM];

int main( void ) {
    
    int n;
    cin >> n;
    
    dp[1] = psm[1] = n;
    dp[2] = ( 1LL * n * n ) % MOD;
    psm[2] = ( psm[1] + dp[2] ) % MOD;
    
    for( int i = 3; i <= n; i ++ ) {
        dp[i] = ( 1LL * (n - 1) * (n - 1) % MOD + psm[i - 3] + dp[i - 1] + (n - i + 2) ) % MOD;
        psm[i] = ( psm[i - 1] + dp[i] ) % MOD;
    }
    
    cout << dp[n] << endl;
    return 0;
}