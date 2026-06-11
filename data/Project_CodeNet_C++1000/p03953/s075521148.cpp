#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define N 100001
#define int long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
int n,x[N],m,k,d[N],p[N],tmp[N],w[N];
void mul(int a[],int b[])
{
	for(int i=1;i<n;++i)
		tmp[i]=a[b[i]];
	memcpy(a,tmp,sizeof tmp);
}
main()
{
	re(n);
	for(int i=1;i<=n;++i)re(x[i]);
	re(m),re(k);
	for(int i=1;i<n;++i)d[i]=p[i]=i;
	for(int x;m--;)
		re(x),swap(d[x],d[x-1]);
	while(k)
	{
		if(k&1)mul(p,d);
		mul(d,d);
		k>>=1;
	}
	for(int i=1;i<n;++i)
		w[i]=x[i+1]-x[i];
	mul(w,p);
	int now=x[1];
	for(int i=1;i<=n;++i)
	{
		printf("%lld\n",now);
		now+=w[i];
	}	
}