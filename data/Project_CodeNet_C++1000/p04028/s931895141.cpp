#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
constexpr lint MOD = 1000000007;

int N, L;

int power(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n & 1) ans = (lint)ans * x % MOD;
        x = (lint)x * x % MOD;
        n >>= 1;
    }
    return ans;
}

int main()
{
    {
        string s;
        cin >> N >> s;
        L = s.size();
    }
    vector<vector<lint> > dp(N+1, vector<lint>(N+2));
    dp[0][0] = 1;
    for (int i=1; i<=N; i++)
    {
        for (int j=0; j<=i; j++)
        {
            dp[i][j] = (dp[i-1][j+1] +  (j ? dp[i-1][j-1] * 2 : dp[i-1][0])) % MOD;
        }
    }
    cout << dp[N][L] * power(power(2, MOD-2), L) % MOD << endl;
}
