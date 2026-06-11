#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
//printf("%.10f\n", n);
ll test[12345678];
signed main() {
    ll n, m, a = 0, ok = 1, ans = 1; cin >> n;
    for (int h = 0; h < n; h++) {
        cin >> test[h];
    }
    for (int h = 0; h < n; h++) {
        a++;
        if (test[h] >= ok) { ok += 2; }
        else { ans *= a; ans %= mod; a--; }
    }
    for (int h = 1; h <= a; h++) { ans *= h; ans %= mod; }
    while (ans < 0) { ans += mod; }
    cout << ans % mod << endl;
    return 0;
}