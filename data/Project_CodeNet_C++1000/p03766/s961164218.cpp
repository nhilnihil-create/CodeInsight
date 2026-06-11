#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1000010;
const ll MOD = ll(1e9 + 7);

int n;
ll f[N];

int main() {
    cin >> n;

    f[0] = 1;
    ll sm = 0;

    for (int i = 0; i <= n; i++) {
        f[i] = (f[i] + sm) % MOD;
        if (i >= 2) {
            f[i] = (f[i] - f[i - 2] + MOD) % MOD;
        }
        if (i == n - 1) {
            f[n] = (f[n] + f[i] * (n - 1) % MOD) % MOD;
        } else if (i < n - 1) {
            f[n] = (f[n] + f[i] * (n - 1) % MOD * (n - 1) % MOD) % MOD;
            f[n] = (f[n] + f[i] * (i + 1)) % MOD;
        }
        sm = (sm + f[i]) % MOD;
    }

    cout << f[n] << endl;
}