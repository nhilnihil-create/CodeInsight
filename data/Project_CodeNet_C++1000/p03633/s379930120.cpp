#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;

    ll ans;
    cin >> ans;
    rep(i, n - 1) {
        ll t;
        cin >> t;
        ans = ans / __gcd(ans, t) * t;
    }

    cout << ans << endl;
    return 0;
}
