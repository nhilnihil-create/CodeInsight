#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll x;
    cin >> x;
    ll a = (x + 10) / 11;
  	ll ans = 2 * a;
    if (11 * a - 5 >= x) ans--;
    cout << ans << endl;
    return 0;
}