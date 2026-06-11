#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 200010
using namespace std;
typedef long long ll;
ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
ll m;
ll a[maxn];
ll f[maxn];
int main()
{
    n=read();m=read();
    for(int i=1;i<=n;i++)  a[i]=read();
    ll ans=0;
    for(int i=1;i<n;i++)
    {
        ll l=a[i],r=a[i+1];
        if(l>r)  r+=m;
        ans+=r-l;
        l+=2;
        if(l>r)  continue;
        f[l]++;f[r+1]-=r-l+2;f[r+2]+=r-l+1;
    }
    for(int i=1;i<=m*2;i++)  f[i]+=f[i-1];
    for(int i=1;i<=m*2;i++)  f[i]+=f[i-1];
    for(int i=1;i<=m;i++)  f[i]+=f[i+m];
    ll res=0;
    for(int i=1;i<=m;i++) res=max(res,f[i]);
    printf("%lld\n",ans-res);
    return 0;
}