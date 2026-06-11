#include <iostream>
#include <cstdio>
using namespace std;

int main()
{   char s[105][105];
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    getchar();
    for(i=0;i<n;i++)
        {for(j=0;j<m;j++)
        scanf("%c",&s[i][j]);
        getchar();
        }
    for(i=0;i<n;i++)
        {for(j=0;j<m;j++)
            printf("%c",s[i][j]);
            printf("\n");
           for(j=0;j<m;j++)
            printf("%c",s[i][j]);
            printf("\n");
        }

    return 0;
}
