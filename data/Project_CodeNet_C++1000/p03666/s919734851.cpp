#include <bits/stdc++.h>
using namespace std;
#define dump(x) cout << (x) << '\n';
typedef int64_t Int;
Int mod = 1e9+7;
Int INF = 1e9+18;

int main() {
    ios::sync_with_stdio(false);
    Int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    for (Int i = 1; i <= n - 1; i++) {
        if (c * (n - 1 - i) - d * i <= b - a && b - a <= d * (n - 1 - i) - c * i) {
            dump("YES");
            return 0;
        }
    }
    dump("NO");
    return 0;
}