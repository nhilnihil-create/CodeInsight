#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(c>a && c<b)
    {
        printf("\n");
        printf("Yes");


    }
    else if (c<a || c>b )
    {
        printf("\n");
        printf("No");
    }
    else if (a=b=c)
    {
        printf("\n");
        printf("Yes");

    }












    return 0;
}