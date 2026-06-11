#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n, a[maxn + maxn];

int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || '9' < ch) { if (ch == '-') f = -f; ch = getchar(); }
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}

bool check(int k) {
    bool tran[maxn]; // 相邻 
    for (int i = 1; i <= n; ++i) tran[i] = a[i] >= k;
    int mid = (n + 1) / 2, pos = 0, flg = -1;
    for (int i = mid; i < n; ++i) { if (tran[i] == tran[i + 1]) { pos = i - mid, flg = tran[i]; break; } }
    for (int i = mid; i > 1; --i) { if (tran[i] == tran[i - 1] && mid - i < pos) { flg = tran[i]; break; } } 
    if (flg != -1) return flg;
    return tran[1];
}

int main() {
    n = read(); n = n + n - 1;
    for (int i = 1; i <= n; ++i) a[i] = read();
    int l = 1, r = n, ans = 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}