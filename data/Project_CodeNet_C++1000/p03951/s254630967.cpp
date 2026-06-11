#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

void solve(void)
{
    int n;
    string s, t;
    cin >> n >> s >> t;
    int ans = 2 * n;
    rep(i, n)
    {
        int cta = 0;
        rep(j, n)
        {
            if (i + j >= n)
                continue;
            if (s[i + j] == t[j])
                cta++;
            else
                continue;
        }
        ans = min(ans, 2 * n - cta);
    }
    cout << ans << endl;
}
int main(void)
{
    solve();
}