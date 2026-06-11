#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, c, k;
    cin >> n >> c >> k;
    int t[n];
    rep(i, n) cin >> t[i];
    sort(t, t + n);

    ll ans = 1, cnt = 0, time = t[0];
    rep(i, n) {
        if (cnt < c && t[i] - time <= k)
            cnt++;
        else
            cnt = 1, time = t[i], ans++;
    }

    cout << ans << endl;
    return 0;
}
