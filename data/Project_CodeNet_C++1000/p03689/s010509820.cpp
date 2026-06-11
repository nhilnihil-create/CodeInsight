#include <bits/stdc++.h>
using namespace std;

int n, m, h, w, a[510][510];

int main() {
    scanf("%d %d %d %d", &n, &m, &h, &w);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = 1000;
        }
    }
    for (int i = h; i <= n; i += h) {
        for (int j = w; j <= m; j += w) {
            a[i][j] = -(h * w - 1) * 1000 - 1;
        }
    }
    long long s = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s += a[i][j];
        }
    }
    printf("%s\n", s > 0 ? "Yes" : "No");
    if (s <= 0) exit(0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}