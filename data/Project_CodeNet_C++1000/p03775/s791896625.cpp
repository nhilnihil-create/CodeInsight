#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int ck(ll a, ll b)
{
    int t_a = 0, t_b = 0;
    while (a)
    {
        t_a++;
        a /= 10;
    }
    while (b)
    {
        t_b++;
        b /= 10;
    }

    return max(t_a, t_b);
}

int main()
{
    ll n;
    cin >> n;

    int ans = 1001001001;
    for (ll a = 1; a * a <= n; a++)
    {
        if (n % a != 0)
        {
            continue;
        }
        ll b = n / a;
        ans = min(ans, ck(a, b));
    }

    cout << ans << endl;
    return 0;
}