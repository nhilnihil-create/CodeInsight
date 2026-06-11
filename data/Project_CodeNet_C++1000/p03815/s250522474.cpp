#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Welcome to my source code!

int main() {
    ll x;
    cin >> x;
    ll ans = x / 11;
    ans *= 2;
    if (x % 11 > 0) ans++;
    if (x % 11 > 6) ans++;
    cout << ans << endl;
}