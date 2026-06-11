#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

ll gcd(ll a, ll b) {
    if(a % b == 0) return b;
    else return(gcd(b, a % b));
}

int main()
{
    int n;
    cin >> n;
    ll ans = 1;
    rep(i, n) {
        ll t;
        cin >> t;
        ll x = gcd(t, ans);
        ans = ans / x * t;
    }
    cout << ans << endl;
    return 0;
}
