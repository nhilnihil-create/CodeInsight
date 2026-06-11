#include <stdio.h>

int main() {
    int x, a, b, d = -1, d2 = -1;
    scanf("%d %d %d", &x, &a, &b);
    d = x - a;
    d2 = x - b;
    if (d < 0) {
        d = a - x;
    }
    if (d2 < 0) {
        d2 = b - x;
    }
    d < d2 ? printf("A") : printf("B");
}