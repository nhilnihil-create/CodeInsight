#include <bits/stdc++.h>
using namespace std;
void solve () {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] + a[i - 1] > x) {
            long long b = max (0, a[i] + a[i - 1] - x);
            ans += b;
            a[i] -= b;
        }
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
