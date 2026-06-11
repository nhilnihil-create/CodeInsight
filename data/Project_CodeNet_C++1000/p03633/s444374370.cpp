#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
int N;
ll gcd(ll a, ll b)
{
    if (a % b == 0)
    {
        return (b);
    }
    else
    {
        return (gcd(b, a % b));
    }
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll ans = 1;
    cin >> N;
    vector<ll> t(N);
    rep(i, 0, N)
    {
        cin >> t[i];
    }
    rep(i, 0, N)
    {
        ans = lcm(ans, t[i]);
        // cout << ans << endl;
    }
    cout << ans << endl;

    return 0;
}
