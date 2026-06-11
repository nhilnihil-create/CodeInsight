#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
//#include "library/debug.cpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll i, o, t, j, l, s, z;
    cin >> i >> o >> t >> j >> l >> s >> z;
    ll ans = 0;
    t = s = z = 0;
    ans = i / 2 * 2 + j / 2 * 2 + l / 2 * 2;
    if (i > 0 && j > 0 && l > 0) {
        ll x = 3;
        i--, j--, l--;
        x += i / 2 * 2 + j / 2 * 2 + l / 2 * 2;
        ans = max(ans, x);
    }
    ans += o;
    cout << ans << endl;

    return 0;
}