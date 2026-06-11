#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100000 + 5, P = 1e9 + 7; 
int n, m, x[N], y[N];
int main() {
    scanf("%d%d", &n, &m);
    ll ans = 0, psum = 0;
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &x[i]);
        ans += 1ll * (i - 1) * x[i] - psum;
        ans %= P;
        psum += x[i];
    }
    ll ans1 = 0;
    psum = 0;
    for (int i = 1; i <= m; ++i) {
        scanf ("%d", &y[i]);
        ans1 += 1ll * (i - 1) * y[i] - psum;
        ans1 %= P;
        psum += y[i];
    }
    cout << (ll)ans1 * ans % P << '\n';
    return 0; 
}