#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= b; ++i)
using namespace std;
#define N 200005
int n;
int a[N], b[N];

inline bool check(int x) {
    rep (i, 1, n * 2 - 1) b[i] = (a[i] >= x ? 1 : 0);
    if (b[n] == b[n - 1] || b[n]== b[n + 1]) return b[n];
    for (int l = n, r = n; l >= 1 && r <= 2 * n - 1; --l, ++r) {
        if (b[l] == b[l + 1]) return b[l];
        if (b[r] == b[r - 1]) return b[r];
    }
    return b[n] ^ (n % 2 == 0);
}

int main() {
    scanf ("%d", &n);
    rep (i, 1, n * 2 - 1) scanf ("%d", &a[i]);
    int l = 1, r = (n << 1) - 1, mid, ans;
    while (l <= r) {
        mid = l + r >> 1;
        if (check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}
