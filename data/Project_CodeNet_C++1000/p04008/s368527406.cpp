#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<queue>
#define mem(a,b) memset(a,b,sizeof(a))
#define mod 20123
#define inf 123456789
#define LL long long
using  namespace std;
int max(int a,int b){ return a>b?a:b;}
int maxn (int a,int b,int c){return max(max(a,b),max(b,c));}
int min(int a,int b){return a<b?a:b;}
LL num[100005],vis[100005],pre[100005],x;
int main()
{
    LL i,j,n,k,ans=0;
    mem(num,0);
    mem(vis,0);
    mem(pre,0);
    scanf("%lld%lld",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&x);
        if(i==1&&x!=1)
        {
            ans++;
        }
        else {
            pre[i]=x;
            num[x]++;
        }
    }
    int m,t;
    queue<int>q;
    for(i=2;i<=n;i++)
        if(num[i]==0) q.push(i);
    while(!q.empty())
    {
        m=q.front();
        q.pop();
        if(m==1) break;
        if(pre[m]!=1&&vis[m]==(k-1))
            ans++;
        else vis[pre[m]]=max(vis[pre[m]],vis[m]+1);
        num[pre[m]]--;
        if(num[pre[m]]==0) q.push(pre[m]);
    }
    printf("%lld\n",ans);
    return 0;
}
