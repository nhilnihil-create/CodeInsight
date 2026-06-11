#include<stdio.h>

int main(void){
    int x;
    char a[] = "ABC",b[] = "ARC";

    scanf("%d",&x);

    if(x >= 1200)
        printf("%s",b);
    else 
        printf("%s",a);

    return 0;
}
