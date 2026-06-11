#include <cstdio>

int main()
{
    int a,b,c,d,e;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a > b)
    {
        printf("%d", b * c + (a - b) * d);
    }
    
    else
    {
        printf("%d", a * c);
    }
    
}