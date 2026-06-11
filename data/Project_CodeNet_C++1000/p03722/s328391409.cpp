#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(m), b(m), c(m);
    rep(i, m) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--;
        c[i] = -c[i];
    }

    vector<ll> dist(n, 1e18);
    dist[0] = 0;
    rep(loop, n - 1) {
        rep(i, m) {
            if (dist[a[i]] == 1e18) continue;
            if (dist[b[i]] > dist[a[i]] + c[i]) {
                dist[b[i]] = dist[a[i]] + c[i];
            }
        }
    }

    ll ans = dist[n - 1];

    vector<bool> neg(n, false);
    rep(loop, n) {
        rep(i, m) {
            if (dist[a[i]] == 1e18) continue;
            if (dist[b[i]] > dist[a[i]] + c[i]) {
                dist[b[i]] = dist[a[i]] + c[i];
                neg[b[i]] = true;
            }
            if (neg[a[i]] == true) {
                neg[b[i]] = true;
            }
        }
    }
    if (neg[n - 1]) puts("inf");
    else
        cout << -ans << endl;
}