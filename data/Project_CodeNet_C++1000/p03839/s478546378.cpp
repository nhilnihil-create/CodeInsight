#include <bits/stdc++.h>
using namespace std;
#define dump(x) cout << (x) << '\n';
typedef int64_t Int;
Int mod = 1e9+7;
Int INF = 1e9+18;

int main() {
    ios::sync_with_stdio(false);
    Int n, k;
    cin >> n >> k;
    vector<Int> a(n);
    vector<Int> b(n + 1, 0);
    vector<Int> c(n + 1, 0);
    Int sum = 0;
    for (Int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 0) sum += a[i];
    }
    for (Int i = 0; i < n; i++) b[i + 1] += b[i] + a[i];
    for (Int i = 0; i < n; i++) {
        if (a[i] > 0) c[i + 1] += a[i];
        c[i + 1] += c[i];
    }
    Int res = 0;
    for (Int i = 0; i <= n - k; i++) {
        Int ma = max((Int)0, b[i + k] - b[i]);
        res = max(res, ma + sum - (c[i + k] - c[i]));
    }
    dump(res);
    return 0;
}