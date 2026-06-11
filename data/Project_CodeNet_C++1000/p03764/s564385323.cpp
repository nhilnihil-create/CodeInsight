#include <bits/stdc++.h>
using namespace std;
const int N = 100005, md = 1000000000 + 7;
int n, x[N], y[N], m;
typedef long long cc;
cc sx[N], sy[N];
cc a, b;
cc process(int n, int x[], cc sx[]) {
    cc sum = 0;
    for (int i = n; i; i--)
        sx[i] = (sx[i + 1] + x[i]) % md;
    for (int i = 1; i <= n; i++)
        sum = (sum + md + sx[i] - (1ll * (n - i + 1) * x[i]) % md) % md;
    return sum;
}
int main() {
//    freopen("input.inp", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= m; i++) cin >> y[i];
    sort (x + 1, x + n + 1);
    sort (y + 1, y + m + 1);
    a = process(n, x, sx);
    b = process(m, y, sy);
    cout << (a * b) % md;
    return 0;
}
