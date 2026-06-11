#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, L, T, a[maxn], x[maxn], w[maxn];

int main() {
    scanf("%d %d %d", &n, &L, &T);
    long long cur = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i], &w[i]);
        if (w[i] == 1) {
            x[i] = (a[i] + T) % L;
            cur += (a[i] + T) / L;
        } else {
            x[i] = (a[i] - T) % L;
            cur += (a[i] - T) / L;
            if (x[i] < 0) cur--, x[i] += L;
        }
    }
    cur = (cur % n + n) % n;
    sort(x + 1, x + n + 1);
    for (int i = cur + 1; i <= n; i++) {
        printf("%d\n", x[i]);
    }
    for (int i = 1; i <= cur; i++) {
        printf("%d\n", x[i]);
    }
    return 0;
}