#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010

int n,l,t,x[MAXN],w[MAXN],p[MAXN],delta;

int main()
{
	scanf("%d%d%d",&n,&l,&t);
	for(int i=1;i<=n;++i)scanf("%d%d",x+i,w+i);
	for(int i=1;i<=n;++i)
	{
		if(w[i]==1)p[i]=(x[i]+t)%l;
		else p[i]=((x[i]-t)%l+l)%l;
	}
	for(int i=1;i<=n;++i)
	{
		if(w[i]==1)delta+=(x[i]+t)/l;
		else delta-=(l-x[i]+t-1)/l;
	}
	sort(p+1,p+n+1);
	p[0]=p[n];
	for(int i=1;i<=n;++i)printf("%d\n",p[((i+delta)%n+n)%n]);
}