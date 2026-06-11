#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll inf = 1LL<<60;
const double eps = 1e-9;

int main()
{
    ll n, t, ans = 0, now = 0;
    cin >> n >> t;
    ll tmp, be;
    cin >> be;
    now = be + t;

    for (int i = 1; i < n; i++) {
        cin >> tmp;
        if (now >= tmp) ans += tmp - be;
        else ans += t;

        now = tmp + t;
        be = tmp;
    }
    cout << ans + t << endl;
    
    return 0;
}