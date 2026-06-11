#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int sum = a + b;

    if (sum > b) {
        printf("Positive");
    } else if (sum >= a) {
        printf("Zero");
    } else {
        if (sum & 1) {
            printf("Positive");
        } else {
            printf("Negative");
        }
    }
}