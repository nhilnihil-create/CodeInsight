/*
样例大良心 qvq
*/
#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

const int N = 1e5 + 10;
int n, a[N], mn = 1e9, mx = -1e9;

int main() {
    cin >> n;
    rep(i, 1, n) {
        scanf("%d", &a[i]);
        mx = max(mx, a[i]), mn = min(mn, a[i]);
    }
    if (mn < mx - 1 || mx > n - 1) return puts("No"), 0;
    if (mn == mx) {
        if (mn == n - 1) puts("Yes");
        else {
            if (mn * 2 > n) puts("No");
            else puts("Yes");
        }
    } else {
        int cnt = 0;
        rep(i, 1, n) if (a[i] == mn) ++cnt;
        if (mn < cnt) puts("No");
        else if ((mx - cnt) * 2 > (n - cnt)) puts("No");
        else puts("Yes");
    }
    return 0;
}
