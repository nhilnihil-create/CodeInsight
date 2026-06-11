#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    for (ll k = 0; k < n; k++) {
        ll lb = c * (n - 1 - k) - d * k;
        ll ub = -c * k + (n - 1 - k) * d;
        if (lb <= b - a && b - a <= ub) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}