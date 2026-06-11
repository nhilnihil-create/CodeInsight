#include <stdio.h>

const int base = 1E9 + 7;

int main() {
    int n; scanf("%d", &n);
    int *f = new int[n + 1];
    f[0] = 0;
    f[1] = n;
    f[2] = 1ll * n * n % base;
    int sum = 0;
    for (int i = 3; i <= n; i++) {
        f[i] = (f[i - 1] + 1ll * (n - 1) * (n - 1) % base) % base;
        f[i] = (f[i] + sum + n - i + 2) % base;
        sum = (sum + f[i - 2]) % base;
    }
    printf("%d", f[n]);
    return 0;
}
