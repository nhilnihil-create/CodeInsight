#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,e;
    while(~scanf("%d%d%d",&a,&b,&e))
    {
         if(e>=a&&e<=b)
            printf("Yes\n");
        else
           printf("No\n");
    }
    return 0;
}
