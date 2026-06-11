#include <bits/stdc++.h>

using namespace std;
#define int long long
int n, dp[5005][5005], m;

string s;

const int mod = 1e9 + 7;

int BinPow(int x, int k){
    if(k == 0)
        return 1;
    else if(k == 1)
        return x;
    else{
        int sum1 = BinPow(x, k/2) % mod;
        sum1 = (sum1 * sum1)%mod;
        if(k % 2 != 0){
            sum1 = (sum1 * x)%mod, sum1 %= mod;
        }
        return sum1;
    }
}

signed main(){
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    cin >> s;
    m = s.length();
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n; j++){
            if(!dp[i][j]) continue;
            if(j == 0){
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j] %= mod;
            }
            else{
                dp[i + 1][j - 1] += dp[i][j];
                dp[i + 1][j - 1] %= mod;
            }
            dp[i + 1][j + 1] += 2 * dp[i][j];
            dp[i + 1][j + 1] %= mod;
        }
    }
    int sum1 = BinPow(2, m);
    cout << (BinPow(sum1, mod - 2) * dp[n][m])%mod << "\n";
}