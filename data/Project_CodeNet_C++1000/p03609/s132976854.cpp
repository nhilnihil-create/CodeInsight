#include <cstdio>

int main()
{
    int a,b,total;
    scanf("%d %d",&a,&b);
    
    if(a > b)
    {
        total = a - b;
    }
    else 
    {
        total = 0;
    }
    printf("%d",total);

    
}