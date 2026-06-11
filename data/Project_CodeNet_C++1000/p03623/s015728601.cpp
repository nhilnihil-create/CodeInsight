#include <stdio.h>

int main() {
    int x, a, b;
    scanf("%d %d %d", &x, &a, &b);
    int diff1 = x > a ? x - a : a - x;
    int diff2 = x > b ? x - b : b - x;
    diff1 > diff2 ? puts("B") : puts("A");
    return 0;
}
