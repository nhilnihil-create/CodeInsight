#include <stdio.h>

int main () {
    int x;
    int a;
    int b;
    int total1;
    int total2;
    scanf("%d%d%d", &x, &a, &b);
    total1 = x-a;
    total2 = x-b;

    if(total1<0){
        total1 = total1 * -1;
}

    if(total2<0){
        total2 = total2 * -1;
    }

    if (total1>total2){
        printf("B");
    }
    if (total1<total2) {
        printf("A");
    }
        return 0;


}