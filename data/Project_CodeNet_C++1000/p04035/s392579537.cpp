#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout << (x) << endl
#define Int int64_t
#define fi first
#define se second

Int INF = 1e18;
Int mod = 1e9+7;
//Int mod = 998244353;

int main() {
    Int n, l;
    cin >> n >> l;
    vector<Int> a(n + 1);
    for (Int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    Int index = -1;
    for (Int i = 1; i <= n - 1; i++) {
        if (a[i] + a[i + 1] >= l) {
            index = i;
        }
    }
    if (index == -1) {
        dump("Impossible");
        return 0;
    }
    dump("Possible");
    for (Int i = 1; i < index; i++) {
        dump(i);
    }
    for (Int i = n - 1; i >= index; i--) {
        dump(i);
    }
    return 0;
}