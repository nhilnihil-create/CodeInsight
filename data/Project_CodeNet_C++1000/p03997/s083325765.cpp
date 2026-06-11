#include <stdio.h>

int main(void){
        int a,b,h;
        scanf("%d %d %d",&a,&b,&h);
        int s = ((a + b) * h) / 2.0;
        printf("%d",s);
        return 0;
}