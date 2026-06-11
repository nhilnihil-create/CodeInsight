#include <iostream>

using namespace std;

const long MOD = 1000000007;

long dp[1000000];
long dp_sum;

int main(){
    long n;
    cin >> n;
    dp[0] = n;
    dp[1] = (n*n)%MOD;
    dp_sum = 0;
    for(int i = 2; i <= n-1; i++){
        dp[i] = dp[i-1]+dp_sum+(n-1)*(n-1)+(n-(i-1));
        dp[i] %= MOD;
        dp_sum += dp[i-2];
        dp_sum %= MOD;
    }
    cout << dp[n-1] << endl;
}