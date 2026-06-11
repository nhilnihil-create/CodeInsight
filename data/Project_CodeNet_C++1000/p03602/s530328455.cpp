#include <cstdio>

int n, a[333][333];
long long s;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int flag = 0;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) {
                    continue;
                }
                if (a[i][k] + a[k][j] < a[i][j]) {
                    puts("-1");
                    return 0;
                }
                if (a[i][k] + a[k][j] == a[i][j]) {
                    flag = 1;
                }
            }
            if (!flag) {
                s += a[i][j];
            }
        }
    }

    printf("%lld", s);

    return 0;
}