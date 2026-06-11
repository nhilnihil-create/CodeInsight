#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll inf = 1LL<<60;
const double eps = 1e-9;

int main()
{
    ll x;
    cin >> x;

    ll ans = 0;
    ans += x/11 * 2;

    ll tmp = x%11;
    if (tmp > 6) ans += 2;
    else if (tmp > 0) ans += 1;
    else ans;

    cout << ans << endl; 
    return 0;
}
