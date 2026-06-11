#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

void solve(void)
{
    string s;
    cin >> s;
    int ans = 0;
    int len = s.length();
    int cta = 0;
    rep(i, len)
    {
        if (s[i] == 'S')
            cta++;
        else if (s[i] == 'T' && cta > 0)
            cta--;
        else
            ans++;
    }
    cout << ans + cta << endl;
}
int main(void)
{
    solve();
}