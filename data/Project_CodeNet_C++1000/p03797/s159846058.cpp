#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    if (n >= m) {
        ans = m / 2;
    } else {
        ans += n;
        m -= 2 * n;
        ans += m / 4;
    }
    cout << ans << endl;
}