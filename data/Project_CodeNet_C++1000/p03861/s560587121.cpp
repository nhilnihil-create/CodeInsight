#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int MOD = 1e9 + 7;
#define rep(i, n) for (int i = 0; i < int(n); ++i)

//-------------------ここから回答する-----------------------

void solve(void)
{
    ll a, b, x;
    cin >> a >> b >> x;
    ll i = b / x;
    ll j;
    if (a == 0)
        j = -1;
    else
        j = --a / x;
    cout << i - j << endl;
}
int main(void)
{
    solve();
}
