#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    ll a, b, x;
    cin >> a >> b >> x;
    ll l = a / x;
    ll r = b / x;
    if(a % x == 0) {
        cout << r - l + 1 << endl;
    }
    else cout << r - l << endl;
    return 0;
}
