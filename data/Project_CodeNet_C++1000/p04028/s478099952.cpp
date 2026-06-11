#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>

using namespace std;

long long MOD = 1000000007;

long long dp[50001][5001];

int BIT_SIZE = 64;
long long power(long long m, long long n){
    long long ans = 1;
    long long tmp = m;
    for(int i = 0; i < BIT_SIZE; i++){
        //cout << ans << endl;
        if(((n >> i) & 1) == 1){
            ans = ans * tmp % MOD;
        }
        tmp = (tmp * tmp) % MOD;
    }
    return ans;
}

long long inv(long long a){
    return power(a, MOD - 2);
}

int main(){
    int N;
    string s;
    cin >> N;
    cin >> s;

    dp[0][0] = 1;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= N; j++){
            if(j == 0){
                dp[i][j]  = (dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
            } else if (j==N){
                dp[i][j] = (dp[i - 1][j - 1] * 2) % MOD;
            } else {
                dp[i][j] = ((dp[i - 1][j - 1] * 2) % MOD + (dp[i - 1][j + 1]) % MOD) % MOD; 
            }
        }
    }

    long long ans = dp[N][s.size()];
    long long inv2 = inv(2);
    for(int i = 0; i < s.size(); i++){
        ans = (ans * inv2) % MOD;
    }    
    cout << ans << endl;
    return 0;
}