#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

//組み合わせの数nCrを計算
ll nCr(ll n, ll r)
{
    ll num = 1;
    for (ll i = 1; i <= r; i++)
    {
        num = num * (n - i + 1) / i;
    }
    return num;
}

int main()
{
    int n, p;
    cin >> n >> p;
    int x = 0, y = 0;
    rep(i, n)
    {
        int a;
        cin >> a;
        if (a % 2 == 0)
            x++;
        else
            y++;
    }

    ll ans = pow(2, x);
    if (p == 0)
    {
        ll tmp = 0;
        for (int i = 0; i <= y; i += 2)
        {
            tmp += nCr(y, i);
        }
        ans *= tmp;
    }

    if (p == 1)
    {
        ll tmp = 0;
        for (int i = 1; i <= y; i += 2)
        {
            tmp += nCr(y, i);
        }
        ans *= tmp;
    }

    cout << ans << endl;
}