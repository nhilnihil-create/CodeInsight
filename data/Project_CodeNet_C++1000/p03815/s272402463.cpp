#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define all(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
const int mod = 1e9+7;

int main() {
    ll x;
    cin >> x;
    ll ans;
    if (x % 11 == 0) {
        ans = x / 11 * 2;
    } else {
        if (x % 11 <= 6) {
            ans = x / 11 * 2 + 1;
        } else {
            ans = x / 11 * 2 + 2;
        }
    }
    cout << ans << endl;
}