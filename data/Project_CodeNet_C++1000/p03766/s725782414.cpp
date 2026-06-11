#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e6 + 10, NX = 1e9 + 7;
int n, dp[MXN], PS[MXN];
int main()
{
    scanf("%d", &n);
    dp[0] = 1; PS[0] = 1;
    dp[1] = n; PS[1] = n + 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = (1ll * (n - 1) * (n - 1) + n - i + 1 + dp[i - 1]) % NX;
        if (i >= 3)
            dp[i] = (dp[i] + PS[i - 3]) % NX;
        PS[i] = (PS[i - 1] + dp[i]) % NX;
    }
    return !printf("%d", dp[n]);
}
