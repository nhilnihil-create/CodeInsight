#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

typedef long long ll;

const int N=1e5+9;

ll k,p[N];
int n,m,a[N],ans[N],tmp[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&p[i]);
	for(int i=1;i<n;i++)
		a[i]=ans[i]=i;
	scanf("%d%lld",&m,&k);
	for(int i=1,v;i<=m;i++)
	{
		scanf("%d",&v);
		swap(a[v-1],a[v]);
	}

	while(k)
	{
		if(k&1)
			for(int i=1;i<n;i++)
				ans[i]=a[ans[i]];
		for(int i=1;i<n;i++)
			tmp[i]=a[a[i]];
		for(int i=1;i<n;i++)
			a[i]=tmp[i];
		k>>=1;
	}

	ll x=p[1];
	for(int i=1;i<=n;i++)
	{
		printf("%lld.0\n",x);
		x+=p[ans[i]+1]-p[ans[i]];
	}

	return 0;
}
