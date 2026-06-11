#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1100000;
int n;
int f[N], ans;
int main()
{
    cin >> n;
    f[0] = 1; f[1] = 2; f[2] = 3;
    for (int i = 3; i <= n; ++ i)
        f[i] = (0ll + MOD + f[i - 1] + f[i - 1] - (f[i - 2] - f[i - 3])) % MOD;
    // for (int i = 1; i <= n; ++ i) cerr << f[i] << endl;
    for (int i = 0; i < n - 1; ++ i)
        ans = (ans + 1ll * (f[i] + (i? MOD - f[i - 1]: 0)) * (1ll * (i + 2 - (i == n - 2)) * n % MOD + 1ll * (n - 1 - (i + 2 - (i == n - 2))) * (n - 1) % MOD)) % MOD;
    ans = (ans + 1ll * (f[n - 1] + MOD - f[n - 2]) * n) % MOD;
    cout << ans << endl;
}
