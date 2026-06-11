#include <cstdio>

int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);

    if(a == b && a == c && b == c)
    {
        printf("1");
    }
    else if((a == b && a != c) || (b == c && b != a) || (a == c && a != b))
    {
        printf("2");
    }
    else
    {
        printf("3");
    }
    
    
}