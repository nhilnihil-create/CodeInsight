#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9+7;
const int MAX = 1e6+1;
int64_t dp[MAX], dps[MAX];

int main(){
    int64_t N;
    cin >> N;
    dp[1] = dps[1] = N;
    dp[2] = N*N % MOD;
    dps[2] = (dp[1] + dp[2]) % MOD;
    for(int i=3; i<=N; i++){
        dp[i] = ((N-1)*(N-1) + dp[i-1] + dps[i-3] + N-i+2) % MOD;
        dps[i] = (dp[i] + dps[i-1]) % MOD;
    }
    cout << dp[N] << endl;
    return 0;
}