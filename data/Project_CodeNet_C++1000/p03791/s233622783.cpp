#include <bits/stdc++.h>
using namespace std;
int n;
#define N 200000
int ai[N], rb[N], dt[N];
int ans = 1;
#define MOD 1000000007
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> ai[i];
    for (int i = 1, d = 0, p = 0; i <= n; ++ i)
    {
        d = max(d, i - 1 - (ai[i - 1] + 1) / 2);
        ans = 1ll * ans  * (i - d) % MOD;
    }
    cout << ans;
}
