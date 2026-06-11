#include<stdio.h>

int main(void)
{
        int i,j,l;
        char a[11],b[11],c[11];

        scanf("%s%s%s",&a,&b,&c);

        i=j=l=0;
        while(a[i] != '\0')
          i++;
        i=i-1;

        while(b[j] != '\0')
          j++;
        j=j-1;

        if(a[i] == b[0]){
          if(b[j] == c[0])
            printf("YES\n");
          else
            printf("NO\n");
   }
        else
          printf("NO\n");

        return 0;
}
