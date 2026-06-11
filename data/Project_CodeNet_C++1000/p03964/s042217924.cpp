#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define inf LLONG_MAX
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
    ll n; cin >> n;
    ll t = 1, a = 1;
    rep(i, n) {
        ll x, y; cin >> x >> y;
        ll m = max((t + (x - 1)) / x, (a + (y - 1)) / y);
        t = m * x, a = m * y;
    }
    cout << t + a << endl;
    return 0;
}