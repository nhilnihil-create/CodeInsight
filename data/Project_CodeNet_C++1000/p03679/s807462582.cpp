#include<stdio.h>

int main() {
    int x, a, b;
    scanf("%d %d %d", &x, &a, &b);
    if (b <= a)
        printf("delicious");
    else if (b <= a + x)
        printf("safe");
    else
        printf("dangerous");
    return 0;
}