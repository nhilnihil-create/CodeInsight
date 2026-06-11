#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define repr(i, n) for (int i = (n); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
    ll r = a % b;
    if (r == 0)
        return b;
    return gcd(b, r);
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

ll cl(ll a, ll b)
{
    return (a + (b - 1)) / b;
}

int main()
{
    ll n;
    cin >> n;

    ll t, a;
    cin >> t >> a;
    rep(i, n - 1)
    {
        ll T, A;
        cin >> T >> A;
        ll m = max(cl(t, T), cl(a, A));
        t = T * m, a = A * m;
    }
    OP((ll)(t + a));
    return 0;
}