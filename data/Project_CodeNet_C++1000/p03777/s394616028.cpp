#include <cstdio>

int main()
{
    char a,b;
    scanf("%c %c",&a,&b);
    
    if(a == 'H' && b == 'H')
    {
        printf("H");
    }
    else if(a == 'H' && b == 'D')
    {
        printf("D");
    }
    else if(a == 'D' && b == 'H')
    {
        printf("D");
    }
    else
    {
        printf("H");
    }
}