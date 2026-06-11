#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int n,l,q,x[maxn],fa[maxn][18],sum[maxn],summ;
inline void pre()
{
	register int i,j=2;
	for(i=1;i<=n;++i)
	{
		while(summ+sum[j]-sum[j-1]<=l&&j<=n) summ+=sum[j]-sum[j-1],++j;
		fa[i][0]=j-1;
		summ-=sum[i+1]-sum[i];
	}
	for(i=1;i<=17;++i)
		for(j=1;j<=n;++j)
			fa[j][i]=fa[fa[j][i-1]][i-1];
}
inline void solve(int a,int b)
{
	if(a>b) swap(a,b);
	int ans=0;
	for(register int i=17;i>=0;--i)
		if(fa[a][i]<b) a=fa[a][i],ans+=(1<<i);
	printf("%d\n",++ans);
}
int main()
{
	scanf("%d",&n);
	register int i;
	for(i=1;i<=n;++i)
		scanf("%d",&x[i]),sum[i]=sum[i-1]+x[i]-x[i-1];
	scanf("%d%d",&l,&q);
	pre();
	int a,b;
	for(i=1;i<=q;++i)
		scanf("%d%d",&a,&b),solve(a,b);
	return 0;
}