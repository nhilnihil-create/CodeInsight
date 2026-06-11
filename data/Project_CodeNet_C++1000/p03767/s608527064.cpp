#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep1(i, n) for (int i = 1; i <= n; ++i)

int main() {
    ll int n, ans = 0;
    cin >> n;
    vector<ll int> a(3 * n);
    rep(i, 3 * n) { cin >> a.at(i); }
    sort(a.begin(), a.end());
    for (int i = n; i < 3 * n; i += 2) {
        ans += a.at(i);
    }
    cout << ans << endl;
    return 0;
}