#include <bits/stdc++.h>
using namespace std;

long long n, x, ans = 1e18, a[2005], dp[2005][2005];

int main()
{
    scanf("%lld%lld", &n, &x);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = a[i];
        for (int j = 1; j < n; j++)
        {
            int now = i - j;
            if (now < 1)
                now += n;
            dp[i][j] = min(dp[i][j - 1], a[now]);
        }
    }
    for (int j = 0; j < n; j++)
    {
        long long sum = j * x;
        for (int i = 1; i <= n; i++)
            sum += dp[i][j];
        ans = min(sum, ans);
    }
    printf("%lld", ans);
    return 0;
}