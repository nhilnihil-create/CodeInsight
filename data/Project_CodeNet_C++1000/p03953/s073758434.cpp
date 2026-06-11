#include<bits/stdc++.h>
using namespace std;
int t,n,m,a,p[100005],ans[100005],tmp[100005],i;
int x[100005];
long long k;
double s=0;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&x[i]);
	for(i=n;i>=2;--i)
		x[i]-=x[i-1];
	for(i=1;i<=n;++i)
		ans[i]=p[i]=i;
	scanf("%d %lld",&m,&k);
	for(i=1;i<=m;++i)
	{
		scanf("%d",&a);
		swap(p[a],p[a+1]);
	}
	for(i=1;i<=n;++i)
		tmp[p[i]]=i;
	for(i=1;i<=n;++i)
		p[i]=tmp[i];
	while(k)
	{
		if(k&1)
		{
			for(i=1;i<=n;++i)
				tmp[i]=p[ans[i]];
			for(i=1;i<=n;++i)
				ans[i]=tmp[i];
		}
		for(i=1;i<=n;++i)
			tmp[i]=p[p[i]];
		for(i=1;i<=n;++i)
			p[i]=tmp[i];
		k>>=1;
	}
	for(i=1;i<=n;++i)
		tmp[ans[i]]=x[i];
	for(i=1;i<=n;++i)
	{
		s+=tmp[i];
		printf("%.12lf\n",s);
	}
}