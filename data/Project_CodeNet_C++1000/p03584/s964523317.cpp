#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int n,k,tot,head[55],nex[N],to[N],fi[N],se[N];
void add(int u,int x,int y)
{
    ++tot;nex[tot]=head[u];head[u]=tot;fi[tot]=x;se[tot]=y;
}
int upbit(int x)
{
    for(int i=30;i>=0;i--)
        if(x>>i&1) return i;
    return -1;
}
long long sum[55];
int main()
{
    //freopen("01.txt","r",stdin);
    scanf("%d%d",&n,&k);
    long long ans=0,res=0;
    int u=upbit(k);
    for(int i=1;i<=n;i++)
    {
        int a,b;scanf("%d%d",&a,&b);
        int k=upbit(a);
        if(k==-1||(a&k)==a) res+=b;
        else add(k,a,b),sum[k]+=b;
    }
    for(int i=u;i>=0;i--)
    {
        if(k>>i&1)
        {
            long long s=0;
            for(int j=i-1;j>=0;j--)
                s+=sum[j];
            ans=max(ans,res+s);
            for(int j=head[i];j;j=nex[j])
            {
                int f=fi[j],s=se[j];
                f^=1<<i;
                int k=upbit(f);
                if(k==-1) res+=s;
                else add(k,f,s),sum[k]+=s;
            }
        }
    }
    ans=max(ans,res);
    printf("%lld\n",ans);
}
