#include <stdio.h>

int main() {
    int kids;
    long int sum = 0;
    scanf("%d", &kids);
    for (int i = 1; i <= kids; i++) {
        sum += i;
    }
    printf("%ld", sum);
}