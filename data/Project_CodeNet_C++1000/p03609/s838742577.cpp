#include<stdio.h>
int main(void){
    int x,t;
    scanf("%d%d",&x,&t);
    if(x-t<0)
    printf("0");
    else
    {
        printf("%d",x-t);
    }
    
    return 0;
}