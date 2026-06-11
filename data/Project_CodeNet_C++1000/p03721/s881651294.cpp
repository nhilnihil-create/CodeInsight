#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    ll n, k;
    cin >> n >> k;
    map<ll, ll> m;
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        m[a] += b;
    }

    ll cnt = 0;
    for (auto e : m) {
        cnt += e.second;
        if (k <= cnt) {
            cout << e.first << endl;
            return 0;
        }
    }

    return 0;
}
