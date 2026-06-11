#include <bits/stdc++.h>
using namespace std;

const int H_MAX = 1e5, MOD = 1e9 + 7;

int h, w, a, b;

int ans, lin, col;
int fact[2 * H_MAX + 2];

void factorial();
int exp(int a, int b);
int comb(int n, int k);

int main()
{
    factorial();

    cin >> h >> w >> a >> b;

    int row, col = b + 1, cur, i, j;
    for(row = 1; row < h - a; row++)
    {
        cur = comb(row + col - 2, col - 1);

        i = h - row + 1, j = w - col;
        cur = (1LL * cur * comb(i + j - 2, j - 1)) % MOD;

        ans = (1LL * ans + cur) % MOD;
    }

    row = h - a;
    cur = comb(row + col - 2, col - 1);

    i = h - row + 1, j = w - col + 1;
    cur = (1LL * cur * comb(i + j - 2, j - 1)) % MOD;

    ans = (1LL * ans + cur) % MOD;

    cout << ans << '\n';

    return 0;
}

void factorial()
{
    fact[0] = fact[1] = 1;
    for(int i = 2; i <= 2 * H_MAX; i++)
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
}

int exp(int a, int b)
{
    int ans;
    for(ans = 1; b; b >>= 1)
    {
        if(b & 1) ans = (1LL * ans * a) % MOD;
        a = (1LL * a * a) % MOD;
    }

    return ans;
}

int comb(int n, int k)
{
    return (1LL * fact[n] * exp(fact[k], MOD - 2) % MOD * exp(fact[n - k], MOD - 2) % MOD) % MOD;
}
