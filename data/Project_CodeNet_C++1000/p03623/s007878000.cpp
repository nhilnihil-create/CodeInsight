#include <stdio.h>

int main()
{
    int x,a,b;
    scanf("%d%d%d", &x, &a, &b);
    int xa, xb;
    if(x>a){
        xa= x-a;
    }else (xa= a-x);
    if(x>b){
        xb= x-b;
    }else(xb=b-x);
    if(xa>xb){
        printf("B\n");
    }else printf("A\n");
    return 0;
}