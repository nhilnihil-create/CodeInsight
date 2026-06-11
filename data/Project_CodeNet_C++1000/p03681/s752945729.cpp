#include <bits/stdc++.h>
#define mod 1000000007ll
using namespace std;
typedef long long ll;

ll n, m, ans;
int main() {
    cin >> n >> m;
    if (abs(n - m) >= 2) {
        cout << 0 << endl;
        return 0;
    }
    if (n == m) {
        ans = 2;
    } else {
        ans = 1;
    }
    for (int i = 1; i <= n; i++) {
        ans *= i;
        ans %= mod;
    }
    for (int i = 1; i <= m; i++) {
        ans *= i;
        ans %= mod;
    }
    cout << ans << endl;
}