//Heaplax
//别让自己后悔
#include<bits/stdc++.h>
#define N 100001
#define int long long
#define LOG(x) cerr<<#x<<" = "<<x<<endl
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
int n,L,T,id=1,x[N],w[N],y[N];
main()
{
	re(n);
	re(L);
	re(T);
	for(int i=1;i<=n;++i)
	{
		re(x[i]),re(w[i]);
		if(w[i]==1)
		{
			y[i]=(x[i]+T)%L;
			id-=(x[i]+T)/L;
		}
		else
		{
			y[i]=(x[i]-T%L+L)%L;
			id+=(L-1+T-x[i])/L;
		}
	}
	sort(y+1,y+n+1);
	id=(id%n+n)%n;
	if(!id)id=n;
	for(int i=1;i<=n;++i,id=id%n+1)
		x[id]=y[i];
	for(int i=1;i<=n;++i)
		printf("%lld\n",x[i]);
}
