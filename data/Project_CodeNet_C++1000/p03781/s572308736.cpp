#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n,i,c=0,r=0;
    scanf("%d", &n);
    for(i=1;i<=n;++i)
    {
        c=i;
        r+=i;
        if(r>=n)
        {
            printf("%d", c);
            return 0;
        }
    }
}
