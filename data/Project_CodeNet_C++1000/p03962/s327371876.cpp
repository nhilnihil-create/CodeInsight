#include<stdio.h>

int main()

{
    int a,b,c,d,e;
    scanf("%d%d%d",&a,&b,&c);

    if(a==b && a==c )
        printf("1");

    else if(a==b && a!=c)
        printf("2");

    else if(a==c && a!=b)
        printf("2");

    else if(b==c && b!=a)
        printf("2");

    else if(a!=b && a!=c)
        printf("3");

    return 0;

}