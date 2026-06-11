#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        a[i] += ans;
        ans += (b[i] - a[i] % b[i]) % b[i];
    }
    cout << ans << endl;
}
