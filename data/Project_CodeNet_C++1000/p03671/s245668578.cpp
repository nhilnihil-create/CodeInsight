#include <cstdio>

int main()
{
    int a,b,c,sum;
    scanf("%d %d %d",&a,&b,&c);
    
    if(a<=b || a<=c)
    {
        sum = sum + a;
    }
    if(b<=a || b<=c)
    {
        sum = sum + b;
    }
    if(c<=a || c<=b)
    {
        sum = sum + c;
    }
    if(a == b && a == c && b == c)
    {
        sum = sum - c;
    }
    printf("%d",sum);
}