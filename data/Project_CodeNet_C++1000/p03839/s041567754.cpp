#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 1;
int in[N], pref[N];
signed main()
{
#ifdef home
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#else
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    int n, k, ans = 0, sum = 0;
    ;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> in[i];
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + in[i];
    }
    for (int i = n; i > k; i--)
        if (in[i] > 0)
            sum += in[i];
    for (int l = 1, r = l + k - 1; r <= n; l++, r++)
    {
        ans = max(ans, sum);
        ans = max(ans, sum + pref[r] - pref[l - 1]);
        if (in[l] > 0)
            sum += in[l];
        if (r + 1 <= n && in[r + 1] > 0)
            sum -= in[r + 1];
    }
    cout << ans;
}