#include <bits/stdc++.h>
using namespace std;
#define dump(x) cout << (x) << '\n';
typedef int64_t Int;
Int mod = 1e9+7;
Int INF = 1e9+18;

int main() {
    ios::sync_with_stdio(false);   
    Int n;
    cin >> n;
    vector<Int> a(n), b(n);
    vector<bool> conf(n, false);
    Int ma = -1;
    for (Int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > ma) {
            conf[i] = true;
            ma = a[i];
        }
    }
    for (Int i = 0; i < n; i++) cin >> b[i];
    Int res = 1;
    ma = -1;
    for (Int i = n - 1; i >= 0; i--) {
        if (b[i] > ma) {
            ma = b[i];
            if ((conf[i] && b[i] != a[i]) || (!conf[i] && a[i] < b[i])) {
                dump(0);
                return 0;
            }
        }
        else {
            if (!conf[i]) {
                res *= min(a[i], b[i]);
                res %= mod;
            }
        }
    }
    dump(res);
    return 0;
}