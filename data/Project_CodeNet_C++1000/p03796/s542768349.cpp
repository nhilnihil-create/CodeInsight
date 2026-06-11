#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int MOD = 1e9 + 7;
#define rep(i, n) for (int i = 0; i < int(n); ++i)

//-------------------ここから回答する-----------------------

void solve(void)
{
    int n;
    cin >> n;
    ll ans = n;
    while (--n > 0)
    {
        ans *= n;
        ans %= MOD;
    }
    cout << ans << endl;
}
int main(void)
{
    solve();
}
