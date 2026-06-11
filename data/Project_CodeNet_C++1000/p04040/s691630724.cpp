#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

ll f[200005], g[200005];

ll c(int n, int m) {
    return f[n + m - 2] * g[n - 1] % mod * g[m - 1] % mod;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m, a, b;
    ll z = 0;
    f[0] = 1; g[200000] = 750007460;
    cin >> n >> m >> a >> b;
    for (int i = 1; i <= 200000; i++) f[i] = f[i - 1] * i % mod;
    for (int i = 199999; i >= 0; i--) g[i] = g[i + 1] * (i + 1) % mod;
    for (int i = 1; i <= n - a; i++) z = (z + c(i, b) * c(n - i + 1, m - b)) % mod;
    cout << z;
}
