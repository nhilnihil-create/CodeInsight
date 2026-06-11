#include <bits/stdc++.h>
using namespace std;

int n, mn = 1e9, mx, cnt, a[100010];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        mn = min(mn, a[i]), mx = max(mx, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == mn) cnt++;
    }
    if (mx - mn > 1) {
        printf("No\n"), exit(0);
    }
    if (mn == mx) {
        if (mn == n - 1 || mn * 2 <= n) printf("Yes\n");
        else printf("No\n");
        exit(0);
    }
    if (mx - cnt > 0 && n - cnt >= 2 * (mx - cnt)) printf("Yes\n");
    else printf("No\n");
    return 0;
}