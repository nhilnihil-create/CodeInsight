#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=1e5;
int n,m;
ll k,v[maxn+8];
int a[maxn+8],ans[maxn+8];
bool vis[maxn+8];

ll read()
{
    ll x=0,f=1;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x*f;
}

int main()
{
    n=read();
    for (int i=1;i<=n;i++) v[i]=read(),a[i]=i;
    m=read(),k=read();
    for (int i=1;i<=m;i++)
	{
	    int x=read();
	    swap(a[x-1],a[x]);
	}
    for (int i=1;i<n;i++)
	{
	    if (vis[i]) continue;
	    int x=i,cnt=0,y;
	    while(!vis[x]) cnt++,vis[x]=1,x=a[x];
	    y=x=i;
	    for (int j=1;j<=k%cnt;j++) y=a[y];
	    ans[x]=v[y+1]-v[y],x=a[x],y=a[y];
	    while(x!=i) ans[x]=v[y+1]-v[y],x=a[x],y=a[y];
	}
    ll now=v[1];
    for (int i=1;i<=n;i++) printf("%lld.0\n",now),now+=ans[i];
    return 0;
}
	    
	    
