#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1000000007;

long long modPow(long long a, long long p){
    if(p == 0) return 1;
    long long res = modPow(a, p/2);
    res = (res * res) % MOD;
    if(p%2) res = (res * a) % MOD;
    return res;
}

int main(){
    int N;
    while(cin >> N){
        string S; cin >> S;
        vector<vector<long long>> dp(N+1, vector<long long>(N+1, 0));
        dp[0][0] = 1;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                dp[i+1][j+1] += 2 * dp[i][j];
                dp[i+1][j+1] %= MOD;
                dp[i+1][max(0, j-1)] += dp[i][j];
                dp[i+1][max(0, j-1)] %= MOD;
            }
        }
        cout << (dp[N][S.size()] * modPow(modPow(2, S.size()), MOD-2)) % MOD << endl;
    }
}