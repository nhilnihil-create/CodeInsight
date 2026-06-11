#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef long double ld;

const ll SIZE = 1e5 + 10, S2 = 1e7 * 2, MOD = 1e9 + 7;

ll cnt[52][27];



int main() {
    fastInp;

    ll n, m;
    cin >> n >> m;

    ll ml = 0;
    vector<ll> xs(n);
    for (int i = 0; i < n; i++) cin >> xs[i];

    sort(xs.begin(), xs.end());
    for (int i = 1; i < n; i++) {

        ml += (((xs[i] - xs[i - 1]) * (((i) * (n - i)) % MOD))) % MOD;
        ml %= MOD;
    }

    vector<ll> ys(m);
    ll ans = 0, pr;
    for (int i = 0; i < m; i++) cin >> ys[i];

    sort(ys.begin(), ys.end());
    for (int i = 1; i < m; i++) {
        ans += ((((ys[i] - ys[i - 1]) * (((i) * (m - i)) % MOD))) % MOD * ml) % MOD;
        ans %= MOD;
    }

    cout << ans;
    return 0;
}

