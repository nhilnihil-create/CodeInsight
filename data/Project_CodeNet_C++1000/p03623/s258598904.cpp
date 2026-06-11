#include <stdio.h>

int main(){

    int G, N, D;
    scanf("%d %d %d", &G, &N, &D);

    int R1, R2;

    R1 = G>=N? G-N : N-G;
    R2 = G>=D? G-D : D-G;

    if(R1<R2){
        printf("A");
    }else {
        printf("B");
    }

    return 0;
}