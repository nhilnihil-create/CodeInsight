#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>

#define maxn 5005
#define mod 1000000007
using namespace std;
long long dp[maxn][maxn];

long long qmod(long long a, long long b) {
    long long ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans * a) % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

char a[maxn];
long long n;
int main() {
    dp[0][0] = 1;
    scanf("%lld%s", &n, a);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            //dp[i][j]=(dp[i-1][max(0,j-1)]*2+dp[i-1][j+1]+dp[i][j])%mod;
            dp[i + 1][j + 1] = (dp[i][j] * 2 % mod + dp[i + 1][j + 1] ) % mod;
            dp[i + 1][max(0, j - 1)] = (dp[i + 1][max(0, j - 1)] + dp[i][j]) % mod;
        }
    }
    printf("%lld\n", qmod(qmod((long long) 2, (long long) strlen(a)), mod - 2) * dp[n][strlen(a)] % mod);
    return 0;
}