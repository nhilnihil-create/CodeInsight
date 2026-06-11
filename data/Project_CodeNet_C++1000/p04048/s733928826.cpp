#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    ll n, x;
    cin >> n >> x;
    ll ans = n;
    ll h = max(n-x, x);
    ll l = min(n-x, x);
    while(true)
    {
        ll num = h / l;
        if(h % l == 0)
        {
            ans += l * 2 * num - l;
            break;
        }
        ans += l * 2 * num;
        ll tmp = h;
        h = l;
        l = tmp % l;
    }
    cout << ans << endl;
}
