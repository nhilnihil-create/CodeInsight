#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    ll a, b, x;
    cin >> a >> b >> x;

    if (a > 0)
    {
        ll diva = (a - 1) / x;
        ll divb = b / x;

        ll ans = divb - diva;

        cout << ans << endl;
    } else {
        ll diva = -1;
        ll divb = b / x;

        ll ans = divb - diva;

        cout << ans << endl;
    }

    return 0;
}
