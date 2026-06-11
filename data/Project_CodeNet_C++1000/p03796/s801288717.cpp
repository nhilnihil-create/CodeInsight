#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    const int MOD = 1e9 + 7;
    int n;
    cin >> n;

    ll ans = 1;
    for (ll i = 2; i <= n; i++) ans = (ans * i) % MOD;

    cout << ans << endl;
    return 0;
}
