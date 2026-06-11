#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e5+500;
int p[N],siz[N],n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)siz[i]=1;p[1]=1;
    for(int i=1,x,y;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        if(p[x])p[y]=1;
        if(siz[x]==1)p[x]=0;
        ++siz[y],--siz[x];    
    }
    int ans=0;
    for(int i=1;i<=n;i++)if(p[i])++ans;
    cout<<ans<<endl;
}