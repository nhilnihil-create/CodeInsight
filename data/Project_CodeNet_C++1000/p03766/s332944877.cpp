#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

typedef long long ll;

int N;
ll mem = 0,now;
ll dp[1000010] = {1};
ll ans = 0;

int main()
{
    scanf("%d",&N);
    for(int i = 0; i < N; i++)
    {
        mem += dp[i];
        dp[i + 1] += mem;
        dp[i + 1] %= mod;
        dp[i + 2] -= mem;
        dp[i + 2] = (dp[i + 2] + mod) % mod;
        dp[i + 3] += mem;
        dp[i + 3] %= mod;
        now = dp[i];
        //printf("    %lld\n",now);
        if(N - 1 == i)
        {
            ans += now * N % mod;
            ans %= mod;
            continue;
        }
        ans += now * (N - 1) % mod * (N - 1) % mod;
        ans %= mod;
        ans += now * (2 + i - (i == N - 2)) % mod;
        ans %= mod;
        //printf("  %lld\n",ans);
    }
    printf("%lld\n",ans);
    return 0;
}
