#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;
ll MOD = 1e+9 + 7;

// A:3, B:2 => A B A B A
// A:3, B:3 => A B A B A B , B A B A B A
// A:4, B:2 => A B A B A A

int main() {
    ll n, m;
    cin >> n >> m;

    if (abs(n - m) == 0) {
        ll ans = 1;
        for (ll i = n; i > 0; i--) {
            ans *= i;
            ans %= MOD;
            ans *= i;
            ans %= MOD;
        }
        ans *= 2;
        ans %= MOD;
        cout << ans << endl;
    } else if (abs(n - m) == 1) {
        ll ans = 1;
        for (ll i = n; i > 0; i--){
            ans *= i;
            ans %= MOD;
        }
        for (ll i = m; i > 0; i--){
            ans *= i;
            ans %= MOD;
        }

        cout << ans << endl;

    } else {
        cout << 0 << endl;
    }

    return 0;
}
