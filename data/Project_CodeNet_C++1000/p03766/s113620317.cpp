#include <bits/stdc++.h>
#define int long long 

using namespace std;
const int somod = 1e9 + 7;
const int maxn = 1e6 + 7;
int n, dp[maxn];
void Add(int &a, int b)
{
    a += b;
    if(a >= somod) a -= somod;
    if(a < 0) a += somod;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen("test.inp", "r")) freopen("test.inp", "r", stdin);
    cin >> n;
    dp[1] = n;
    dp[0] = 1;
    int sum = 0;
    for(int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + (n - 1) * (n - 1) + sum + (n - i + 1)) % somod;

        Add(sum, dp[i - 2]);
    }
    cout << dp[n];
}