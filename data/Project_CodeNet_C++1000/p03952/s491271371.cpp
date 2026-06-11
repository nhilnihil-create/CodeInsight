#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
int n, x, a[N], b[N];
int main() {
    scanf("%d%d", &n, &x);
    if (x == n) {
        puts("Yes");
        for (int i = 1; i < 2 * n; i++) printf("%d\n", i);
    } else if (x == 1 || x == 2 * n - 1)
        puts("No");
    else {
        puts("Yes");
        for (int i = 1; i < 2 * n; i++) b[i] = 1;
        if (x == 2 * n - 2) {
            a[n] = 2 * n - 1;
            b[2 * n - 1] = 0;
            a[n + 1] = x;
            b[x] = 0;
            a[n + 2] = 1;
            b[1] = 0;
            a[n - 1] = 2;
            b[2] = 0;
        } else {
            a[n] = 1;
            b[1] = 0;
            a[n + 1] = x;
            b[x] = 0;
            a[n + 2] = 2 * n - 1;
            b[2 * n - 1] = 0;
            a[n - 1] = 2 * n - 2;
            b[2 * n - 2] = 0;
        }
        int j = 1;
        for (int i = 1; i < 2 * n; i++) {
            if (!b[i]) continue;
            while (a[j]) j++;
            a[j] = i;
        }
        for (int i = 1; i < 2 * n; i++) printf("%d\n", a[i]);
    }
    return 0;
}