#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <array>
#include <vector>
#include <utility>
#include <bitset>
#include <queue>

using namespace std;

typedef long long ll;

constexpr ll MOD = 1e9 + 7;

ll n, m;

ll get_edge_len(ll n, vector<ll> X) {
    ll xall = 0;
    ll k = 0;
    vector<ll> D(n - 1);
    for (ll i = 0; i < n - 1; i++) {
        D[i] = X[i + 1] - X[i];
    }

    ll len = D.size();
    for (ll i = 0; i < len / 2; i++) {
        k += len - 2 * i;
        xall = (xall + ((k * D[i]) % MOD) + MOD) % MOD;
        xall = (xall + ((k * D[len - 1 - i]) % MOD) + MOD) % MOD;
    }

    if (len % 2) {
        ll i = len / 2;
        k += len - 2 * i;
        xall = (xall + ((k * D[i]) % MOD) + MOD) % MOD;
    }

    return xall;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    vector<ll> X(n), Y(m);
    for (auto&& x : X) {
        cin >> x;
    }
    for (auto&& y : Y) {
        cin >> y;
    }

    ll xall = 0, yall = 0;

    /*
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            xall = (xall + X[i] - X[j]) % MOD;
        }
    }

    for (ll i = 0; i < m; i++) {
        for (ll j = i + 1; j < m; j++) {
            yall = (yall + Y[i] - Y[j]) % MOD;
        }
    }

    cout << xall << "," << yall << endl;

    cout << "reset" << endl;
    xall = yall = 0;
    */

    // xall = get_edge_len(n, X);
    // yall = get_edge_len(m, Y);

    // cout << xall << "," << yall << endl;

    // from editorial
    for (ll i = 0; i < n; i++) {
        xall = (xall + (i * X[i] - (n - 1 - i) * X[i])) % MOD;
    }

    for (ll i = 0; i < m; i++) {
        yall = (yall + (i * Y[i] - (m - 1 - i) * Y[i])) % MOD;
    }

    cout << (xall * yall) % MOD << endl;

    return 0;
}

