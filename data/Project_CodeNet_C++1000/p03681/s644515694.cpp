#include <bits/stdc++.h>
using namespace std;

int64_t factorial(int n) {
    int64_t cal = 1;
    for (int k = 1; k <= n; k++) {
        cal *= k;
        cal %= 1000000007;
    }
    return cal;
}

int main() {
    int N, M; cin >> N >> M;
    int t = abs(N - M);
    if (t >= 2) {
        cout << 0 << endl;
    } else {
        int64_t fn, fm, ans;
        int e = 1;
        if (!t) e = 2;
        fn = factorial(N);
        fm = factorial(M);
        ans = e * fn * fm % 1000000007;
        cout << ans << endl;
    }
}