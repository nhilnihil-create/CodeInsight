/**
*    author:  yuya1234
*    created: 24.06.2020 15:29:49
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REPD(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORD(i, a, b) for (ll i = a; i >= (ll)(b); i--)

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll a, b, x, ans = 0;
    cin >> a >> b >> x;

    if (a % x == 0)
        ans = b / x - a / x + 1;
    else
        ans = b / x - a / x;

    cout << ans << endl;

    return 0;
}