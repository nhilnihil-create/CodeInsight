#include <iostream>

using namespace std;

const long MOD = 1000000007;

long pow2(int n){
    long ans = 1;
    for(int i = 0; i < n; i++){
        ans *= 2;
        ans %= MOD;
    }
    return ans;
}

long inv(int n){
    if(n == 1) return 1;
    return (-(MOD/n)*inv(MOD%n)%MOD+MOD)%MOD;
}

long dp[5001][5001];


int main(){
    int N;
    string s;
    cin >> N;
    cin >> s;
    int n = s.size();
    dp[0][0] = 1;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= 5000; j++){
            if(dp[i-1][j] > 0) {
                dp[i][j+1] = dp[i-1][j]*2;
                dp[i][j+1] %= MOD;
                if(j != 0) {
                    dp[i][j-1] += dp[i-1][j];
                    dp[i][j-1] %= MOD;
                }
                else {
                    dp[i][j] += dp[i-1][j];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    
    long ans = (dp[N][n]*inv(pow2(n)))%MOD;
    cout << ans << endl;
}