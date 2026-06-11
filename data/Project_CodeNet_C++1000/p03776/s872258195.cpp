#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, a, b, e = 0, f = 0;
    ll c[55] = {}, d = 0, g[55][55] = {1};
    for (int i = 1; i <= 50; i++) {
        g[i][0] = 1;
        for (int j = 1; j <= i; j++) g[i][j] = g[i - 1][j] + g[i - 1][j - 1];
    }
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) cin >> c[i];
    sort(c, c + n); reverse(c, c + n);
    for (int i = 0; i < a; i++) d += c[i];
    for (int i = 0; i < n; i++) {
        if (c[i] == c[a - 1]) e++;
        if (c[i] > c[a - 1]) f++;
    }
    ll z = 0;
    if (c[0] == c[a - 1]) for (int i = a; i <= b; i++) z += g[e][i - f];
    else z = g[e][a - f];
    cout << fixed << setprecision(13) << d * 1.0 / a << '\n';
    cout << z << '\n';
}
