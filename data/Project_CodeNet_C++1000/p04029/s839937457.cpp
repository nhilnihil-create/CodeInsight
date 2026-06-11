#include <stdio.h>

int main() {

    int t, i, res=0;

    scanf("%d", &t);
    for(i=0; i<=t; i++) {
        res += i;
    }

    printf("%d", res);

    return 0;
}