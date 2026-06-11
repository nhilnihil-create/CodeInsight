#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int n;

typedef long long LL;

const LL mod = 1e9 + 7;
const int maxn = 1e6 + 5;
LL dp[maxn];
LL pre[maxn];
int main(){
    cin >> n;
    dp[1] = n;
    pre[1] = n;
    dp[2] = 1LL * n * n % mod;
    pre[2] = (dp[1] + dp[2]) % mod;
    dp[3] = dp[2] + 1LL * (n - 1) * (n - 1) + (n - 1);
    dp[3] %= mod;
    pre[3] = (pre[2] + dp[3]) % mod;
    for(int i = 4;i <= n;i++){
        dp[i] = dp[i - 1];
        dp[i] += 1LL * (n - 1) * (n - 1);
        dp[i] += pre[i - 3];
        dp[i] += (n + 2 - i);
        dp[i] %= mod;
        pre[i] = (pre[i - 1] + dp[i]) % mod;
    }
    cout << dp[n] << endl;
    return 0;
}
