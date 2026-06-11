#include <stdio.h>

int main() {
    int x, A, B;
    scanf("%d %d %d", &x, &A, &B);

    if (x, A, B >= 1 && x, A, B <= 1000) {
        if (x < A && x < B) {
            if (A - x < B - x) {
                printf("A\n");
            } else {
                printf("B\n");
            }
        } else if (x > A && x > B) {
            if (x - A < x - B) {
                printf("A\n");
            } else {
                printf("B\n");
            }
        } else {
            if (x > A && x < B) {
                if (x - A < B - x) {
                    printf("A\n");
                } else {
                printf("B\n");
                }
            } else {
                if (x - B < A - x) {
                    printf("B\n");
                } else {
                printf("A\n");
                }
            }
        }
    }

    return 0;
}