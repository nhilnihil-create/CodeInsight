#include <bits/stdc++.h>
 
using namespace std;
 
int r,c,n,x,y,ans[200][200];
 
int main(void)
{
    scanf("%d%d%d",&r,&c,&n);
    x=1,y=1;
    for(int i=1,cnt;i<=n;i++)
    {
        scanf("%d",&cnt);
        while(cnt--)
        {
            ans[x][y]=i;
            if(y==c&&x%2==1)
                y=c,x++;
            else if(y==1&&x%2==0)
                y=1,x++;
            else if(x&1)
                y++;
            else
                y--;
        }
    }
    for(int i=1;i<=r;i++)
    for(int j=1;j<=c;j++)
        printf("%d%c",ans[i][j],j==c?'\n':' ');
    return 0;
}