#include<bits/stdc++.h>
using namespace std;
int n,m,a[301][301],ans=0x3f3f3f3f,x[301];
bool use[301],pd=0;
int clac()
{
    int maxx=0,re;
    pd=1;
    memset(x,0,sizeof(x));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(use[a[i][j]]==0)
            {
                x[a[i][j]]++;
                pd=0;
                break;
            }
        }
    }
    if(pd==1)
        return 0;
    for(int i=1;i<=m;i++)
    {
        if(x[i]>maxx)
        {
            maxx=x[i];
            re=i;
        }
    }
    ans=min(ans,maxx);
    return re;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    while(pd==0)
        use[clac()]=1;
    cout<<ans;
}