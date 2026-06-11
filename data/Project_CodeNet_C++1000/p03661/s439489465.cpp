#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = 1e9 + 7;
const int N = 100100;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    ll total = 0, s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total += a[i];
    }
    ll ans = abs(a[0] * 2 - total);
    for (int i = 0; i + 1 < n; ++i) {
        s += a[i];
        ans = min(ans, abs(s * 2 - total));
    }
    cout << ans;
    return 0;
}