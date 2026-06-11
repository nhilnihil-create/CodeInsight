#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    ll a[100005] = {}, b[100005] = {}, c = 0, d = 0, e = 0, f = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < n; i++) c = (c + i * a[i] - e) % mod, e += a[i];
    for (int i = 0; i < m; i++) d = (d + i * b[i] - f) % mod, f += b[i];
    cout << c * d % mod;
}
