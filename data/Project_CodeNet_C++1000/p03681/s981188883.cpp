//解説AC
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
int main() {
    ll n, m;
    cin >> n >> m;
    if (n < m) {
        swap(n, m);
    }
    if(n > m + 1) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;

    for (ll i = 1; i <= n; i++) {
        ans = (ans * i) % mod;
    }
      for (ll i = 1; i <= m; i++) {
        ans = (ans * i) % mod;
    }

    if(n == m) {
        ans = (2 * ans) % mod;
    }

    cout << ans << endl;
    return 0;
}
