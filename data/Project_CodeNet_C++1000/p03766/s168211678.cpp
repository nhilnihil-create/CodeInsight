#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
int N;
int dp[1000002], psum[1000002];

int main() {
    scanf("%d", &N);

    dp[1] = N;
    psum[1] = dp[1];
    for(int i = 2; i <= N; i++) {
        if(i != 2) {
            dp[i] += psum[i - 1] + mod - dp[i - 2];
            dp[i] %= mod;
            dp[i] += 1LL * (N - 1) * (i - 3) % mod;
            dp[i] %= mod;

        }
        dp[i] += 1LL * (N - i + 2) * N % mod;
        dp[i] %= mod;
        psum[i] = (dp[i] + psum[i - 1]) % mod;
    }
    printf("%d", dp[N]);
}
