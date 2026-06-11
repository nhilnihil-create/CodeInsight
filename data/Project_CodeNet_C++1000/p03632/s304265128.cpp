/**
*    author:  yuya1234
*    created: 24.06.2020 14:57:44
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

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d;

    if (a > c)
        e = a;
    else
        e = c;

    if (b > d)
        f = d;
    else
        f = b;

    if (f - e > 0)
        cout << f - e << endl;
    else
        cout << 0 << endl;

    return 0;
}