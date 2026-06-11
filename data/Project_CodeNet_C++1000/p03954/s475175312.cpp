#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
int n, a[N], mid;
bool d(int x) { return a[x] >= mid; }
bool check() {
    for (int i = 1; i < n; i++) {
        if (d(n + i) == d(n + i - 1)) return d(n + i);
        if (d(n - i) == d(n - i + 1)) return d(n - i);
    }
    return d(1);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n - 1; i++) scanf("%d", &a[i]);
    int l = 1, r = 2 * n - 1, ans = 0;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check())
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}