#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int N;
    ll x;
    cin >> N >> x;
    vector<ll> a(N);
    for (ll& v : a) {
        cin >> v;
    }

    vector<vector<ll>> b(N, vector<ll>(N, 1e18));
    for (int i = 0; i < N; i++) {
        b[0][i] = a[i];
    }
    for (int k = 1; k < N; k++) {
        for (int i = 0; i < N; i++) {
            int prv = (i - k + N) % N;
            b[k][i] = min(b[k - 1][i], a[prv]);
        }
    }
    ll ans = 1e18;
    for (ll k = 0; k < N; k++) {
        ans = min(ans, x * k + accumulate(b[k].begin(), b[k].end(), 0ll));
    }
    cout << ans << endl;
}
