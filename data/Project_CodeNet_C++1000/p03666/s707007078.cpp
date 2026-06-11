#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    --n;
    int w = b - a;
    for (int i = 0; i <= n; ++i) {
        int l = i * -d + (n - i) * c;
        int r = i * -c + (n - i) * d;
        if (l <= w && w <= r) {
            cout << "YES\n";
            exit(0);
        }
    }
    cout << "NO\n";
}
