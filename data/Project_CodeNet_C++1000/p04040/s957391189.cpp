#include <bits/stdc++.h>

#define ll long long
#define NM_MAX 100002

using namespace std;

const int MOD = 1e9+7;

int pwr (int a, int b)
{
    if(b == 0)
        return 1;
    if(b & 1)
        return 1LL * pwr(a, (b ^ 1)) * a % MOD;
    int p = pwr(a, (b >> 1));
    return 1LL * p * p % MOD;
}

int fact[2 * NM_MAX];
int ifact[2 * NM_MAX];

int comb (int a, int b)
{
    return 1LL * fact[a] * ifact[b] % MOD * ifact[a - b] % MOD;
}

int f (int a, int b)
{
    return comb(a - 1 + b - 1, a - 1);
}

int n, m, a, b;

int main()
{
    cin >> n >> m >> a >> b;
    fact[0] = 1;
    for(int i = 1; i <= n + m; i++)
        fact[i] = 1LL * fact[i - 1] * i % MOD;
    ifact[n + m] = pwr(fact[n + m], MOD - 2);
    for(int i = n + m - 1; i >= 0; i--)
        ifact[i] = 1LL * ifact[i + 1] * (i + 1) % MOD;
    int sum = 0;
    for(int i = 1; i <= b; i++)
        sum = (sum + 1LL * f(n - a, i) * f(a, m - i + 1)) % MOD;
    cout << (1LL * f(n, m) - sum + MOD) % MOD;
    return 0;
}
