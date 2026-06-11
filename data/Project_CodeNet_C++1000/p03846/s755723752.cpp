#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int const MOD = 1e9 + 7;
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];
    sort(a, a + n);

    vector<int> v;
    if (n % 2 == 0) {
        rep(i, n / 2) rep(j, 2) v.push_back(2 * i + 1);
    } else {
        rep(i, n / 2 + 1) rep(j, 2) v.push_back(2 * i);
        v.erase(v.begin());
    }

    bool ok = true;
    rep(i, n) if (a[i] != v[i]) ok = false;
    if (!ok) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;
    rep(i, n / 2) ans = (ans * 2) % MOD;
    cout << ans << endl;
    return 0;
}
