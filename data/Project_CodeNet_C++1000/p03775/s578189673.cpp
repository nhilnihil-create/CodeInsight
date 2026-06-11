#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
const int MOD = 1e9 + 7;

ll digit(ll a)
{
    ll ans = 0;

    while (a)
    {
        ans++;
        a /= 10;
    }
    return (ans);
}

int main()
{
    ll n;
    cin >> n;

    ll ans = 1001001001;
    for (ll a = 1; a * a <= n; a++)
    {
        ll b;
        if (n % a != 0)
            continue;
        b = n / a;
        ans = min(ans, max(digit(a), digit(b)));
    }

    cout << ans << endl;
    return (0);
}
