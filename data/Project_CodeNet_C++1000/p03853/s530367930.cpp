#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct chu
{
    char t[101];
}s[101];
int main()
{
      int a,b;
      while(~scanf("%d%d",&a,&b))
      {
         for(int i=1;i<=a;i++)
         {
                scanf("%s",s[i].t);
         }
         for(int j=1;j<=a;j++)
         {
             printf("%s\n",s[j].t);
             printf("%s\n",s[j].t);
         }
      }
    return 0;
}
