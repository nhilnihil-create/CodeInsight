#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

bool prime(ll x) {
    ll i;
    if (x == 1) {
        return false;
    } else {
        for (i = 2; i <= sqrt(x); i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }
}

int main() {
    ll n;
    ll cnt = 0;
    ll ans = 1;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    for (int i = 2; i <= n; i++) {
        if (prime(i)) {
            ll k = 1;
            cnt = 0;
            while (pow(i, k) <= n) {
                cnt += n / pow(i, k);
                k++;
            }
            ans  = (ans * (cnt+1)) % MOD;
        }
    }
    cout << ans % MOD << endl;
}
