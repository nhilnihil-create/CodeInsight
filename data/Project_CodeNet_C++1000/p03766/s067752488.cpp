#include<iostream>
#include<cstdio>
#include<queue>
#define MN 1000000
#define mod 1000000007
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,f[MN+5],g[MN+5],v,ans;
inline void R(int&x,int y){x+=y;x>=mod?x-=mod:0;}
int main()
{
    n=read();f[1]=1;
    for(int i=1;i<=n;++i)
    {
        R(g[i],v);R(v,f[i-1]);R(ans,1LL*f[i]*(i==n?n-1:1LL*i*n%mod)%mod);
        R(f[i+1],g[i]);R(f[i+1],f[i]);
        R(ans,1LL*g[i]*(n-1)%mod);
    }
    R(ans,f[n+1]);R(ans,g[n+1]);
    printf("%d",ans);
    return 0;
}
