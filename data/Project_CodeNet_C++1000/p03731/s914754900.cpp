#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, T;
    cin >> n >> T;
    int t[n];
    rep(i, n) cin >> t[i];

    ll ans = T;
    rep(i, n - 1) ans += min(T, t[i + 1] - t[i]);

    cout << ans << endl;
    return 0;
}
