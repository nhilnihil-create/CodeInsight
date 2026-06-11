#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, n) for (int i = 1; i <= (n); ++i)

int main() {
    ll n, ans = 10000000;
    string sa, sb;
    cin >> n;
    for (ll i = 1; i * i <= n; ++i) {
        ll j = n / i;
        if (i * j == n) {
            sa = to_string(i);
            sb = to_string(j);
            ll tmp = max(sa.length(), sb.length());
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;
    return 0;
}