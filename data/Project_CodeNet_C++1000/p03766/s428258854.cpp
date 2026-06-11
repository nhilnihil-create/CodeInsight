//https://atcoder.jp/contests/arc071/tasks/arc071_d

#include<bits/stdc++.h>
const int N = 2e6 + 5;
const int mod = 1e9 + 7;
using namespace std;

int n, dp[N], sum[N];

void add(int&a, int b){
    a += b; if (a >= mod) a -= mod; if (a < 0) a += mod;
}

int main(){
    cin >> n;
    dp[0] = 1; sum[0] = 1;
    for (int i = 1; i <= 2*n; i++){
        if (i <= n) dp[i] = dp[i-1];
        if (i > 2) add(dp[i], sum[min(i-3, n-2)]);
        if (i > n+1) add(dp[i], -sum[i-n-2]);
        sum[i] = sum[i-1]; add(sum[i], dp[i]);
    }
    cout << (1LL * sum[n-2] * (n-1) % mod * (n-1) + 1LL * dp[n-1] * (n-1) % mod + sum[2*n] - sum[n-1] + mod) % mod;
}
