#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
// Welcome to my source code!

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = 1e11;
    for (int bit = 0; bit < (1 << n); bit++) {
        if (__builtin_popcount(bit) < k) continue;
        int maxh = 0, cnt = 0;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) {
                if (a[i] <= maxh) {
                    sum += maxh - a[i] + 1;
                    maxh++;
                } else cnt++;
            }
            maxh = max(maxh, a[i]);
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
}