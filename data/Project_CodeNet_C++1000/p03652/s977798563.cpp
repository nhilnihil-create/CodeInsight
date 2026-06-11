#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn= 350;
bool vis[maxn];
int mapp[maxn][maxn];
int n,m;
int num[maxn];
int main()
{
    scanf("%d%d",&n,&m);
    for(register int i=1;i<=n;i++)
    {
        for(register int j=1;j<=m;j++)
        {
            scanf("%d",&mapp[i][j]);
        }
    }
    int qq=m;
    int minn=1e9+7;
    memset(vis,1,sizeof(vis));
    while(qq--)
    {
        memset(num,0,sizeof(num));
        int maxx=0,no;
        for(register int i=1;i<=n;i++)
        {
            for(register int j=1;j<=m;j++)
            {
                if(vis[mapp[i][j]])
                {
                    num[mapp[i][j]]++;
                    if(num[mapp[i][j]]>maxx)
                    {
                        maxx=num[mapp[i][j]];
                        no=mapp[i][j];
                    }
                    break;
                }
            }
        }
        vis[no]=false;
        minn=min(minn,maxx);
    }
    printf("%d\n",minn);
    //cout << "Hello world!" << endl;
    return 0;
}
