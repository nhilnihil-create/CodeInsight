#include<stdio.h>

int main()

{
    int n,k,x,y,a;
    scanf("%d%d%d%d",&n,&k,&x,&y);

    if(n<k)
    {
        a=n*x;
        printf("%d",a);
    }

    else
    {
        a=k*x+(n-k)*y;
        printf("%d",a);

    }
    return 0;
}