#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//23:02
ll a[20];
int main() {
    int n,k;
    cin >> n >> k;
    ll ans = 1e18;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < (1 << n); i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) cnt++;
        }
        if (cnt >= k) {
            ll h = 0;
            ll sum = 0;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    if (a[j] <= h) {
                        sum += h + 1 - a[j];
                        h++;
                    } else {
                        h = a[j];
                    }
                } else {
                    if (a[j] > h) h = a[j];
                }
            }
            ans = min(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;
}