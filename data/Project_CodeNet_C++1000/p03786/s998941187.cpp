// cout << "Case #" << test << ": ";
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<ll> a(n), rui(n + 1, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    for(int i = 0; i < n; i++) {
        rui[i + 1] = rui[i] + a[i];
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int prev = i + 1;
        int now = upper_bound(all(a), 2 * rui[prev]) - a.begin();
        // cout << prev << "**" << now << endl;
        while(now != prev) {
            prev = now;
            now = upper_bound(all(a), 2 * rui[prev]) - a.begin();
            // cout << prev << ":" << now << endl;
        }
        ans += (now == n);
    }
    cout << ans << endl;
}
