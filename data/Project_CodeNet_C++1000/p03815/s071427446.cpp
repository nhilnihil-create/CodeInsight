#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll x; cin >> x;
    ll q = x / 11, r = x % 11;
    ll ans = 2 * q;
    if (r > 6 && r) ans += 2;
    else if (r <= 6 && r) ans += 1;
    cout << ans << endl;
}