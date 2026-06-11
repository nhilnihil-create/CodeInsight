#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    // m = n - 1
    // [a + kc - (m - k)d, a + kd - (m - k)c] contains b
    // a + kc - (m - k)d <= b <=> k(c+d) <= b - a + md = X
    // a + kd - (m - k)c >= b <=> k(c+d) >= b - a + mc = Y
    
    int m = n - 1;
    long long X = 1LL * m * d + b - a;
    long long Y = 1LL * m * c + b - a;
    if (c + d == 0) {
        if ((X >= 0) && (Y <= 0)) cout << "YES\n";
        else cout << "NO\n";
        return 0;
    }
    
    long long mink = 0, maxk = m;
    maxk = min(maxk, X / (c + d));
    mink = max(mink, Y / (c + d) + (Y % (c + d) != 0));
    if (mink <= maxk) cout << "YES\n"; else cout << "NO\n";
}