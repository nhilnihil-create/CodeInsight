#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ll n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ll total = a[i - 1] + a[i];
        if (total > x) {
            total -= x;
            ans += total;
            a[i] -= total;
        }
    }
    cout << ans << endl;
}
