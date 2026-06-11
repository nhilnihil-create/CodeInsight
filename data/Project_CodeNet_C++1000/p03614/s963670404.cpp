#include <bits/stdc++.h>
using namespace std;
int a[200010];
int flag[200010];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(flag,0,sizeof(flag));
        int ans=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
        {
            if(a[i]==i)
            {
                if(flag[i])
                {
                    continue;
                }
                else
                {
                    if(a[i+1]==i+1)
                    {
                        if(flag[i+1]==0)
                        {
                            ans++;
                            flag[i+1]=1;
                            continue;
                        }
                        else continue;
                    }
                    else
                    {
                        ans++;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}
