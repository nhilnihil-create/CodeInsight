#include <iostream>
using namespace std;

using ll = long long;

int main() {
    const ll MOD = 1e9 + 7;

    int n, m;
    cin >> n >> m;

    const int MAXN = 200000;
    const int MAXM = 200000;
    static ll x[MAXN], y[MAXM];
    static ll cumx[MAXN], cumy[MAXM];

    for (int i = 0; i < n; i++) {
        cin >> x[i];

        cumx[i] = x[i];
        if (i > 0) cumx[i] += cumx[i - 1];

        cumx[i] = (cumx[i] + MOD * MOD) % MOD;
    }

    for (int i = 0; i < m; i++) {
        cin >> y[i];

        cumy[i] = y[i];
        if (i > 0) cumy[i] += cumy[i - 1];

        cumy[i] = (cumy[i] + MOD * MOD) % MOD;
    }

    ll xterm = 0,
       yterm = 0;
    for (int i = 0; i < n; i++) {
        xterm += ((i + 1) * x[i] - cumx[i] + MOD * MOD) % MOD;
        xterm %= MOD;
    }
    for (int i = 0; i < m; i++) {
        yterm += ((i + 1) * y[i] - cumy[i] + MOD * MOD) % MOD;
        yterm %= MOD;
    }

    cout << (xterm * yterm) % MOD << endl;

    return 0;
}