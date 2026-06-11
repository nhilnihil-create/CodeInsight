#include<bits/stdc++.h>
#define N 505
using namespace std;
int n,x[N],a[N*N],cnt[N],b[N],top;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x[i]);
        a[x[i]]=i;
    }
    for(int i=1;i<=n*n;i++)if(a[i])b[++top]=a[i];
    for(int i=1;i<=n;i++)cnt[i]=i-1;
    int now=1;
    for(int i=1;i<=n*n;i++)
    {
        if(!cnt[b[now]])now++;
        if(now!=n+1&&!a[i])
        {
            a[i]=b[now];
            cnt[b[now]]--;
            if(!cnt[b[now]])now++;
        }
    }
    int flag=0;now=n;
    for(int i=1;i<=n;i++)cnt[i]=n-i;
    for(int i=n*n;i>=1;i--)
    {
        if(!cnt[b[now]])now--;
        if(!a[i])
        {
            a[i]=b[now];
            cnt[b[now]]--;
            if(!cnt[b[now]])now--;
        }
    }
    //for(int i=1;i<=n*n;i++)cout<<a[i]<<endl;
   // for(int i=1;i<=n*n;i++)cout<<a[i]<<endl;
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        for(int j=1;j<=x[i];j++)if(a[j]==i)cnt++;
        if(cnt!=i)flag=1;
    }
    if(flag)puts("No");
    else
    {
        puts("Yes");
        for(int i=1;i<=n*n;i++)
        {
            printf("%d ",a[i]);
        }puts("");
    }
    return 0;
}
