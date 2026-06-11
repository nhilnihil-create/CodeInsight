#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

const int MOD = 1e+9 + 7;

template <typename T>
T pow_mod( T n, T p, T m )
{
    if( p == 0 ) return 1;
    if( p%2 == 1 ) return pow_mod(n, p-1, m) * n % m;
    else{
        T tmp = pow_mod(n, p/2, m) % m;
        return tmp * tmp % m;
    }
}


int main()
{
    int N;
    cin >> N;
    string s;
    cin >> s;

    int M = s.size();

    // dp[i][j]: i 回の操作で j (1-index) 文字の文字列を作る場合の数
    vector<vector<long long>> dp(N+1, vector<long long>(N+1));
    dp[0][0] = 1;
    REP(i, N){
        dp[i+1][0] = (dp[i][0] + dp[i][1]) % MOD;
        FOR(j, 1, N){
            dp[i+1][j] = (2*dp[i][j-1] + dp[i][j+1]) % MOD;
        }
        dp[i+1][N] = (2*dp[i][N-1]) % MOD;
    }

    cout << (dp[N][M]*pow_mod<long long>(2, (long long) M*(MOD-2), MOD)) % MOD << endl;

    return 0;
}