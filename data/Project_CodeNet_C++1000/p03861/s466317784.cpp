#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;
// ------------------------------

int main() {
    ll a, b, x;
    cin >> a >> b >> x;
    ll ans = 0;
    if (a == 0) {
        a = 1;
        ans += 1;
    }
    ans += b / x - (a - 1) / x;
    cout << ans << endl;
    return 0;
}