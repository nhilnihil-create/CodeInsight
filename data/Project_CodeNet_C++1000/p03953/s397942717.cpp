#include<bits/stdc++.h>
#define L long long
using namespace std;
int n,m,x[100010],a[100010];
L p;
struct orz
{
	int a[100010];
	inline orz operator*(orz x)
	{
		orz p;
		int i;
		for(i=1;i<n;i++)
		  p.a[i]=a[x.a[i]];
		return p;
	}
}u[70],w;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	L k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {
	   scanf("%d",&x[i]);
	   w.a[i]=u[0].a[i]=i;
	  }
	scanf("%d%lld",&m,&p);
	for(i=1;i<=m;i++)
	  {
	   scanf("%d",&j);
	   swap(u[0].a[j],u[0].a[j-1]);
	  }
	for(i=1;i<60;i++)
	  u[i]=u[i-1]*u[i-1];
	for(i--;i>=0;i--)
	  if(p&(1ll<<i))
	    w=w*u[i];
	for(i=1;i<n;i++)
	  a[i]=x[w.a[i]+1]-x[w.a[i]];
	for(i=0,k=x[1];i<n;i++,k+=a[i])
	  printf("%lld\n",k);
	return 0;
}
