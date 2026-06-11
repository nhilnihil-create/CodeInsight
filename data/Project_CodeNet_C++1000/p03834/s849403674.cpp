#include <stdio.h>

int main (){
    char n[19];
    scanf("%s", n);

    n[5] -=12;
    n[13] -=12;

    printf("%s\n", n);

    return 0;
}