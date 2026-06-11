#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
        ll n, x;
    cin >> n >> x;
    ll ans = n;
    ll a = x, b = n - x;
    while (b % a != 0)
    {
        ans += 2 * a * (b / a);
        ll tmp = a;
        a = b % a;
        b = tmp;
    }
    ans += a * (2 * (b / a) - 1);
    cout << ans << endl;
    return 0;
}