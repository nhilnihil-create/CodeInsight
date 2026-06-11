#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    const ll mod = 1000000007;
    ll n, m; cin >> n >> m;
    ll ans = 1;
    
    
    if (n == 1 && m == 1) {
        ans = 2;
    }
    else if (n == m) {
        ans *= 2;
        ll cnt = n;
        while (cnt--) {
            ans *= n;
            ans %= mod;
            ans *= m;
            ans %= mod;
            n--;
            m--;
        }
    }
    else if (n == m + 1 || n + 1 == m) {
        ll cnt, x;
        if (n == m + 1) {
            ans *= n;
            cnt = m;
            x = m;
        }
        else {
            ans *= m;
            cnt = n;
            x = n;
        }

        while (cnt--) {
            ans *= x;
            ans %= mod;
            ans *= x;
            ans %= mod;
            x--;
        }
    }
    else {
        ans = 0;
    }

    cout << ans << endl;
    return 0;
}