#include <cstdio>

int main()
{
    int a;
    scanf("%d",&a);
    
    if(a/100 == a%10)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    
}